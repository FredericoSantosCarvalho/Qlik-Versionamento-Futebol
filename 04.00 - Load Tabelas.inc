TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Início da Carga'
-------------------------------------------------------------;

Fato_Futebol:
LOAD
    %Time_Image,
    %Time,
    %Ano,
    %AnoEscalacoes,
    %Data,
    "Time",
    Status,
    Pts,
    "Status Time",
    Rodada,
    Estádio,
    Arbitro,
    Púlico,
    "Público Max",
    Técnico,
    Colocação,
    "Valor Equipe",
    "Idade Média",
    "Gols Geral",
    "Gols Feitos",
    "Gols Sofridos",
    "Gols 1 Tempo",
    Escanteio,
    Faltas,
    "Chute Bola Parada",
    Defesas,
    Impedimentos,
    Chutes,
    "Chutes fora",
    Público,
    Tecnico
FROM [lib://Futebol:DataFiles/TR_Fato_Futebol.qvd]
(qvd);

Dim_Artilheiro:
LOAD
    %Ano,
    %Artilheiro,
    Equipe,
    Gols
FROM [lib://Futebol:DataFiles/TR_Dim_Artilheiro.qvd]
(qvd);

Dim_Caldendario:
LOAD
    %Data,
    Semana,
    Ano,
    Mês,
    Dia,
    CurYTDFlag,
    LastYTDFlag,
    "Mês Ano"
FROM [lib://Futebol:DataFiles/TR_Dim_Caldendario.qvd]
(qvd);

TR_Ilha_Escalacoes:
LOAD
    "Time Ilha",
    "Pos",
    Jogadores,
    Formação,
    %AnoEscalacoes,
    Zn,
    Meio,
    Ata
FROM [lib://Futebol:DataFiles/TR_Ilha_Escalacoes.qvd]
(qvd);
