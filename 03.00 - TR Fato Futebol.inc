TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Início da Transformção'
-------------------------------------------------------------;

TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Fato Futebol'
-------------------------------------------------------------;

TR_Fato_Futebol:
LOAD
	time_mandante											as %Time_Image,
    time_mandante&ano_campeonato							as %Time,
    ano_campeonato											as %Ano,	
    ano_campeonato											as %AnoEscalacoes,
    data													as %Data,
    time_mandante											as Time,
    /***************************************************************************************
    If para cálculo das vitórias, derrotas e empates dos times mandantes	
    ***************************************************************************************/    
    IF( gols_mandante>gols_visitante
    	,'V'
        ,IF(	gols_visitante=gols_mandante
        		,'E'
                ,'D'
        )
	    
    )														as [Status],
    /***************************************************************************************
    If para cálculo da pontuação dos times mandantes
    ***************************************************************************************/
    IF( gols_mandante>gols_visitante
    	,3
        ,IF(	gols_visitante=gols_mandante
        		,1
                ,0
        )
	    
    )														as [Pts],    
    'Mandante'												as [Status Time],
    rodada													as [Rodada],
    estadio													as [Estádio],
    arbitro													as [Arbitro],
    publico													as [Púlico],
    publico_max												as [Público Max],
    tecnico_mandante										as [Técnico],
    colocacao_mandante										as [Colocação],
    valor_equipe_titular_mandante							as [Valor Equipe],
    idade_media_titular_mandante							as [Idade Média],
    gols_mandante											as [Gols Geral],
    gols_mandante											as [Gols Feitos],
    gols_visitante											as [Gols Sofridos],
    gols_1_tempo_mandante									as [Gols 1 Tempo],
    escanteios_mandante										as [Escanteio],
    faltas_mandante											as [Faltas],
    chutes_bola_parada_mandante								as [Chute Bola Parada],
    defesas_mandante										as [Defesas],
    impedimentos_mandante									as [Impedimentos],
    chutes_mandante											as [Chutes],
    chutes_fora_mandante									as [Chutes fora]
FROM [lib://Futebol:DataFiles/EX_Brasileirao_Serie_A.qvd]
(qvd);


Concatenate(TR_Fato_Futebol)

LOAD
	time_visitante											as %Time_Image,
    time_visitante&ano_campeonato							as %Time,
    ano_campeonato											as %Ano,
    ano_campeonato											as %AnoEscalacoes,
    data													as %Data,
    time_visitante											as Time,
    /***************************************************************************************
    If para cálculo das vitórias, derrotas e empates dos times visitantes	
    ***************************************************************************************/    
    IF( gols_visitante>gols_mandante
    	,'V'
        ,IF(	gols_visitante=gols_mandante
        		,'E'
                ,'D'
        )
	    
    )														as [Status],
    /***************************************************************************************
    If para cálculo da pontuação dos times visitantes	
    ***************************************************************************************/    
    IF( gols_visitante>gols_mandante
    	,3
        ,IF(	gols_visitante=gols_mandante
        		,1
                ,0
        )
	    
    )														as [Pts],    
    'Visitante'												as [Status Time],    
    rodada													as [Rodada],
    estadio													as [Estádio],
    arbitro													as [Arbitro],
    publico													as [Público],
    publico_max												as [Público Max],
    tecnico_visitante										as [Tecnico],
    colocacao_visitante										as [Colocação],
    valor_equipe_titular_visitante							as [Valor Equipe],
    idade_media_titular_visitante							as [Idade Média],
    gols_visitante											as [Gols Geral],
    gols_visitante											as [Gols Feitos],
    gols_mandante											as [Gols Sofridos],
    gols_1_tempo_visitante									as [Gols 1 Tempo],
    escanteios_visitante									as [Escanteio],
    faltas_visitante										as [Faltas],
    chutes_bola_parada_visitante							as [Chute Bola Parada],
    defesas_visitante										as [Defesas],
    impedimentos_visitante									as [Impedimentos],
    chutes_visitante										as [Chutes],
    chutes_fora_visitante									as [Chutes fora]
FROM [lib://Futebol:DataFiles/EX_Brasileirao_Serie_A.qvd]
(qvd);


STORE TR_Fato_Futebol INTO [lib://Futebol:DataFiles/TR_Fato_Futebol.qvd](qvd);
