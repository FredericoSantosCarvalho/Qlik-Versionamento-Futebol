TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Dim Calendário'
-------------------------------------------------------------;
Temp:  
Load  
	min(%Data) 												as minDate,  
	max(%Data) 												as maxDate  
Resident TR_Fato_Futebol;  
      
Let varMinDate = Num(Peek('minDate', 0, 'Temp'));  
Let varMaxDate = Num(Peek('maxDate', 0, 'Temp'));  
DROP Table Temp;  

//Gera todas as datas do mínimo ao máximo
TempCalendar:  
LOAD  
	$(varMinDate) + Iterno()-1 								as Num,  
	Date($(varMinDate) + IterNo() - 1) 						as TempDate  
AutoGenerate 1 While $(varMinDate) + IterNo() -1 <= $(varMaxDate);  

//Criar o calendário através das funções mínimo e máximo
TR_Dim_Caldendario:  
Load  
  	TempDate 												as %Data,  
  	week(TempDate) 											as Semana,  
  	Year(TempDate) 											as Ano,  
  	Month(TempDate) 										as Mês,  
  	Day(TempDate) 											as Dia,  
  	YearToDate(TempDate)*-1									as CurYTDFlag,
  	YearToDate(TempDate,-1)*-1								as LastYTDFlag,
  	Date(MonthStart(TempDate),'MM/YYYY')					as [Mês Ano]
Resident TempCalendar  
Order By TempDate ASC;  
Drop Table TempCalendar;  


STORE TR_Dim_Caldendario INTO [lib://Futebol:DataFiles/TR_Dim_Caldendario.qvd](qvd);
DROP TABLES TR_Dim_Caldendario, TR_Fato_Futebol;