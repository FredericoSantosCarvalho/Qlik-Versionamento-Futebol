<<<<<<< HEAD
=======
﻿/*******************************************************************************************************
	Consultor: 	Frederico Santos
    Objetivo:	Aba para extração das tabelas.
*******************************************************************************************************/




>>>>>>> 30b74cdcd111980cc5ca2e9a4bba9e97d522cb81
TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Início da Extração'
-------------------------------------------------------------;




EX_Brasileirao_Serie_A:
LOAD
    ano_campeonato,
    data,
    rodada,
    estadio,
    arbitro,
    publico,
    publico_max,
    time_mandante,
    time_visitante,
    tecnico_mandante,
    tecnico_visitante,
    colocacao_mandante,
    colocacao_visitante,
    valor_equipe_titular_mandante,
    valor_equipe_titular_visitante,
    idade_media_titular_mandante,
    idade_media_titular_visitante,
    gols_mandante,
    gols_visitante,
    gols_1_tempo_mandante,
    gols_1_tempo_visitante,
    escanteios_mandante,
    escanteios_visitante,
    faltas_mandante,
    faltas_visitante,
    chutes_bola_parada_mandante,
    chutes_bola_parada_visitante,
    defesas_mandante,
    defesas_visitante,
    impedimentos_mandante,
    impedimentos_visitante,
    chutes_mandante,
    chutes_visitante,
    chutes_fora_mandante,
    chutes_fora_visitante
FROM [lib://Futebol:DataFiles/brasileirao_serie_a.csv]
(txt, utf8, embedded labels, delimiter is ',', msq);

STORE EX_Brasileirao_Serie_A INTO [lib://Futebol:DataFiles/EX_Brasileirao_Serie_A.qvd](qvd);
DROP TABLE EX_Brasileirao_Serie_A;



EX_Artilheiro:
LOAD
    ANO,
    VENCEDOR,
    EQUIPE,
    GOLS
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Artilheiros);

STORE EX_Artilheiro INTO [lib://Futebol:DataFiles/EX_Artilheiro.qvd](qvd);
DROP TABLE EX_Artilheiro;



EX_Escalacoes:
LOAD
    "Time",
    Formação,
    Goleiro,
    Defesa,
    "Meio-campo",
    Ataque,
    Ano
FROM [lib://Futebol:DataFiles/brasileirao.xlsx]
(ooxml, embedded labels, table is Escalacoes);

STORE EX_Escalacoes INTO [lib://Futebol:DataFiles/EX_Escalacoes.qvd](qvd);
DROP TABLE EX_Escalacoes;

