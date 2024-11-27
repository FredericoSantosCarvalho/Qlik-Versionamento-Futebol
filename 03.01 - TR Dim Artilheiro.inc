TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Dim Artilheiro'
-------------------------------------------------------------;

TR_Dim_Artilheiro:
LOAD
    ANO														as %Ano,
    VENCEDOR												as %Artilheiro,
    EQUIPE													as Equipe,
    GOLS													as Gols
FROM [lib://Futebol:DataFiles/EX_Artilheiro.qvd]
(qvd);


STORE TR_Dim_Artilheiro INTO [lib://Futebol:DataFiles/TR_Dim_Artilheiro.qvd](qvd);
DROP TABLE TR_Dim_Artilheiro;