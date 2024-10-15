TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Dim Escalações'
-------------------------------------------------------------;

Dim_Escalacoes:
/*********************************************************************************************
Tratamento das escalações, apenas os casos dos zagueiros, quanto tem 3 na posição. Ex: 3-4-3 	
*********************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField(Defesa,',',1)			as Zn1, 
    SubField(Defesa,',',2)			as Zn2,
    SubField(Defesa,',',3)			as Zn3
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',1)	= 3
;

Concatenate
/*********************************************************************************************
Tratamento das escalações, apenas os casos dos zagueiros, quanto tem 4 na posição. Ex: 4-3-3 	
*********************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField(Defesa,',',1)			as Zn1, 
    SubField(Defesa,',',2)			as Zn2,
    SubField(Defesa,',',3)			as Zn3,
    SubField(Defesa,',',4)			as Zn4
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',1)	= 4
;

Concatenate
/*********************************************************************************************
Tratamento das escalações, apenas os casos dos zagueiros, quanto tem 5 na posição. Ex: 5-3-2 	
*********************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField(Defesa,',',1)			as Zn1, 
    SubField(Defesa,',',2)			as Zn2,
    SubField(Defesa,',',3)			as Zn3,
    SubField(Defesa,',',4)			as Zn4,
    SubField(Defesa,',',5)			as Zn5    
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',1)	= 5
;

Concatenate

/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Meio, quanto tem 4 na posição. Ex: 4-3-3 	
*********************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Meio-campo],',',1)	as Meio1, 
    SubField([Meio-campo],',',2)	as Meio2,
    SubField([Meio-campo],',',3)	as Meio3
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',2)	= 3  
;

Concatenate

/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Meio, quanto tem 5 na posição. Ex: 4-4-2 	
*********************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Meio-campo],',',1)	as Meio1, 
    SubField([Meio-campo],',',2)	as Meio2,
    SubField([Meio-campo],',',3)	as Meio3,
    SubField([Meio-campo],',',4)	as Meio4
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',2)	= 4  
;

Concatenate

/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Meio, quanto tem 4 na posição. Ex: 3-5-2 	
*********************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Meio-campo],',',1)	as Meio1, 
    SubField([Meio-campo],',',2)	as Meio2,
    SubField([Meio-campo],',',3)	as Meio3,
    SubField([Meio-campo],',',4)	as Meio4,
    SubField([Meio-campo],',',5)	as Meio5
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',2)	= 5
;

Concatenate

/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Atacante, quanto tem 1 na posição. Ex: 4-5-1 	
****+****************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Ataque],',',1)		as Ataque1
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',3)	= 1
;

Concatenate
/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Atacante, quanto tem 4 na posição. Ex: 4-4-2 	
****+****************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Ataque],',',1)		as Ataque1, 
    SubField([Ataque],',',2)		as Ataque2
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',3)	= 2
;

Concatenate

/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Atacante, quanto tem 4 na posição. Ex: 4-3-3 	
****+****************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Ataque],',',1)		as Ataque1, 
    SubField([Ataque],',',2)		as Ataque2,
    SubField([Ataque],',',3)		as Ataque3
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	SubField([Formação],'-',3)	= 3
;


Concatenate



/*********************************************************************************************
Tratamento das escalações, apenas os casos dos Goleiro. 	
****+****************************************************************************************/ 
LOAD
    "Time"							as [Time Ilha],
   	SubField([Goleiro],',',1)		as Go
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes)
Where 
 	Len(Goleiro) > 0
;

TR_Ilha_Escalacoes:
CrossTable(Pos,Jogadores,1)
Load
	[Time Ilha],
    Zn1,
    Zn2,
    Zn3,
    Zn4,
    Zn5,
    Meio1,
	Meio2,
	Meio3,
	Meio4,
	Meio5,
    Ataque1, 
	Ataque2,
	Ataque3,
    Go  
Resident Dim_Escalacoes;

Drop Table Dim_Escalacoes;


Left Join
LOAD
    [Time]							as [Time Ilha],
    Text(Formação)					as [Formação],
    2022							as [%AnoEscalacoes],
    SubField([Formação],'-',1)		as Zn,
    SubField([Formação],'-',2)		as Meio,
    SubField([Formação],'-',3)		as Ata
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes);


STORE TR_Ilha_Escalacoes INTO [lib://Futebol:DataFiles/TR_Ilha_Escalacoes.qvd](qvd);
DROP TABLE TR_Ilha_Escalacoes;

