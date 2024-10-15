TRACE
-------------------------------------------------------------
 > Iniciando Carga: 'Variáveis'
-------------------------------------------------------------;


//-------------------------------------------------------------------------------------
//		TRATAMENTO MEDIDAS DE TIMES
//-------------------------------------------------------------------------------------
Set v_Ano					= Max(Ano);


Set v_NumRodadas			= Max(Rodada);
Call TratarExpansaoMacro(v_NumRodadas);

Set v_Vitorias				= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'V'}>}Status);
Call TratarExpansaoMacro(v_Vitorias);

Set v_Derrotas				= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'D'}>}Status);
Call TratarExpansaoMacro(v_Derrotas);

Set v_Empates				= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'E'}>}Status);
Call TratarExpansaoMacro(v_Empates);

Set v_Pontuacao 			= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Pts]);
Call TratarExpansaoMacro(v_Pontuacao);

Set v_Chutes				= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Chutes]);
Call TratarExpansaoMacro(v_Chutes);

Set v_ChutesBolaParada		= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Chute Bola Parada]);
Call TratarExpansaoMacro(v_ChutesBolaParada);

Set v_ChutesFora			= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Chutes fora]);
Call TratarExpansaoMacro(v_ChutesFora);

Set v_Defesa				= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Defesas]);
Call TratarExpansaoMacro(v_Defesa);

Set v_Impedimentos			= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Impedimentos]);
Call TratarExpansaoMacro(v_Impedimentos);

Set v_Faltas				= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Faltas]);
Call TratarExpansaoMacro(v_Faltas);

Set v_Escanteio				= 
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Escanteio]);
Call TratarExpansaoMacro(v_Escanteio);

Set v_Idade_Media			=
Avg({<Rodada={"<=@(=Max(Rodada))"}>}[Idade Média]);
Call TratarExpansaoMacro(v_Idade_Media);

Set v_Valor_Equipe			=
Avg({<Rodada={"<=@(=Max(Rodada))"}>}[Valor Equipe]);
Call TratarExpansaoMacro(v_Valor_Equipe);

Set v_Total_Gols			=
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Gols Geral]);
Call TratarExpansaoMacro(v_Total_Gols);

Set v_Media_Publico			=
Avg({<Rodada={"<=@(=Max(Rodada))"}>}[Público]);
Call TratarExpansaoMacro(v_Media_Publico);

Set v_Total_Arbitros		=
Count(distinct{<Rodada={"<=@(=Max(Rodada))"}>} Arbitro);
Call TratarExpansaoMacro(v_Total_Arbitros);

Set v_Media_Gols			=
Avg({<Rodada={"<=@(=Max(Rodada))"}>}[Gols Geral]);
Call TratarExpansaoMacro(v_Media_Gols);

Set v_Gols_Sofridos			=
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Gols Sofridos]);
Call TratarExpansaoMacro(v_Gols_Sofridos);

Set v_Gols_Feitos			=
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Gols Feitos]);
Call TratarExpansaoMacro(v_Gols_Feitos);

Set v_Gols_Saldo			=
Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Gols Feitos]-[Gols Sofridos]);//-Sum({<Rodada={"<=@(=Max(Rodada))"}>}[Gols Sofridos]);
Call TratarExpansaoMacro(v_Gols_Saldo);

Set v_Total_Jogos_Estadio	=
Count({<Rodada={"<=@(=Max(Rodada))"},[Status Time]={'Mandante'}>}[Estádio]);
Call TratarExpansaoMacro(v_Total_Jogos_Estadio);

//-------------------------------------------------------------------------------------
//		TRATAMENTO MEDIDAS DE CLASSIFICAÇÃO TIMES
//-------------------------------------------------------------------------------------
Set v_Posicao_Time			=
Aggr(
        Rank(
            @(v_Pontuacao) +@(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
            4, 
            1
        ), [Time]
);
Call TratarExpansaoMacro(v_Posicao_Time);




Set v_Classificacao_Time	=
IF(
    Aggr(
        Rank(
            @(v_Pontuacao) +@(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
            4, 
            1
        ), Time
    ) <= 4, 
    'Libertadores',
    IF(
        Aggr(
            Rank(
                @(v_Pontuacao) + @(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
                4, 
                1
            ), Time
        ) > 4 AND 
        Aggr(
            Rank(
                @(v_Pontuacao) + @(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
                4, 
                1
            ), Time
        ) <= 6, 
        'Pré Libertadores',
        IF(
            Aggr(
                Rank(
                    @(v_Pontuacao) + @(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
                    4, 
                    1
                ), Time
            ) > 6 AND 
            Aggr(
                Rank(
                    @(v_Pontuacao) + @(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
                    4, 
                    1
                ), Time
            ) <= 12, 
            'Sulamericana',
            IF(
                Aggr(
                    Rank(
                         @(v_Pontuacao) + @(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
                        4, 
                        1
                    ), Time
                ) > 12 AND 
                Aggr(
                    Rank(
                        @(v_Pontuacao) + @(v_Vitorias)/100 + @(v_Gols_Saldo)/10000, 
                        4, 
                        1
                    ), Time
                ) <= 16, 
                'Sem Competição',
                'Rebaixado'
            )
        )
    )
);
Call TratarExpansaoMacro(v_Classificacao_Time);





//-------------------------------------------------------------------------------------
//		TRATAMENTO TIME ILHA
//-------------------------------------------------------------------------------------
Set v_VitoriasIlha	= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'V'},Time={'@(v_Time_Ilha)'}>}Status);
Call TratarExpansaoMacro(v_VitoriasIlha);


Set v_DerrotasIlha			= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'D'},Time={'@(v_Time_Ilha)'}>}Status);
Call TratarExpansaoMacro(v_DerrotasIlha);


Set v_EmpatesIlha			= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'E'},Time={'@(v_Time_Ilha)'}>}Status);
Call TratarExpansaoMacro(v_EmpatesIlha);


Set v_PontuacaoIlha			= 
Sum({<Rodada={"<=@(=Max(Rodada))"},Time={'@(v_Time_Ilha)'}>}[Pts]);
Call TratarExpansaoMacro(v_PontuacaoIlha);


Set v_Valor_Equipe_Ilha		=
Num(Avg({<Rodada={"<=@(=Max(Rodada))"},Time={'@(v_Time_Ilha)'}>}[Valor Equipe])/1000000,'#.##0 M');
Call TratarExpansaoMacro(v_Valor_Equipe_Ilha);

Set v_Media_Publico_Ilha	=
Num(Avg({<Rodada={"<=@(=Max(Rodada))"},Time={'@(v_Time_Ilha)'}>}[Público])/1000,'#.##0 k');
Call TratarExpansaoMacro(v_Media_Publico_Ilha);

//-------------------------------------------------------------------------------------
//		TRATAMENTO TIME LEADER
//-------------------------------------------------------------------------------------
Set v_Time_Leader			= Aggr(
								Only({<Rodada={"<=@(=Max(Rodada))"},Colocação={1}>}Time)
                          		,Time,Rodada,Colocação
                        	);
Call TratarExpansaoMacro(v_Time_Leader);

Set v_VitoriasLeader		= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'V'},Time={'@(v_Time_Leader_Novo)'}>}Status);
Call TratarExpansaoMacro(v_VitoriasLeader);

Set v_DerrotasLeader		= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'D'},Time={'@(v_Time_Leader_Novo)'}>}Status);
Call TratarExpansaoMacro(v_DerrotasLeader);

Set v_EmpatesLeader			= 
Count({<Rodada={"<=@(=Max(Rodada))"},Status={'E'},Time={'@(v_Time_Leader_Novo)'}>}Status);
Call TratarExpansaoMacro(v_EmpatesLeader);

Set v_PontuacaoLeader		= 
Sum({<Rodada={"<=@(=Max(Rodada))"},Time={'@(v_Time_Leader_Novo)'}>}[Pts]);
Call TratarExpansaoMacro(v_PontuacaoLeader);

Set v_Valor_Equipe_Leader	=
Num(Avg({<Rodada={"<=@(=Max(Rodada))"},Time={'@(v_Time_Leader_Novo)'}>}[Valor Equipe])/1000000,'#.##0 M');
Call TratarExpansaoMacro(v_Valor_Equipe_Leader);

Set v_Media_Publico_Leader	=
Num(Avg({<Rodada={"<=@(=Max(Rodada))"},Time={'@(v_Time_Leader_Novo)'}>}[Público])/1000,'#.##0 k');
Call TratarExpansaoMacro(v_Media_Publico_Leader);



//-------------------------------------------------------------------------------------
//		TRATAMENTO DAS CORES
//-------------------------------------------------------------------------------------
/*
Set v_Cor_Fundo_Filtro			=	RGB(38,38,38);
Set v_Cor_Botao_Selecionado		=	RGB(38,38,38);
Set v_Cor_Botao					=	RGB(180,180,180);
Set v_Cor_Fundo_Geral			=	RGB(128,128,128);
*/
Set v_Cor_Resultado				=
IF(	@(v_Numero_Rodadas)*3+@(v_PontuacaoIlha)> @(v_PontuacaoLeader)
		,RGB(144,238,144)
    	,RGB(220,20,60)
)	;
Call TratarExpansaoMacro(v_Cor_Resultado);
Set v_Cor_Competicao			=
Pick(Wildmatch([Competição],'Rebaixado'		,'Libertadores'	  ,'Pré Libertadores'	,'Sulamericana'	,'Sem Competição')
						   ,RGB(220,20,60)	,RGB(176,224,230) ,RGB(141,179,187)		,RGB(255,165,0)	,RGB(211,211,211)
);





//-------------------------------------------------------------------------------------
//		TRATAMENTO DAS VARIAÇÕES
//-------------------------------------------------------------------------------------
Set v_Variacao_Vitoria			=
Num(((@(v_VitoriasIlha)-@(v_VitoriasLeader))/@(v_VitoriasLeader))*100,'#.##0,00');
Call TratarExpansaoMacro(v_Variacao_Vitoria);


Set v_Variacao_Empate			=
Num(((@(v_EmpatesIlha)-@(v_EmpatesLeader))/@(v_EmpatesLeader))*100,'#.##0,00');
Call TratarExpansaoMacro(v_Variacao_Empate);

Set v_Variacao_Derrota			=
Num(((@(v_DerrotasIlha)-@(v_DerrotasLeader))/@(v_DerrotasLeader))*100,'#.##0,00');
Call TratarExpansaoMacro(v_Variacao_Derrota);




//-------------------------------------------------------------------------------------
//		TRATAMENTO DO VISUAL ESCALAÇÕES NO MAPA
//-------------------------------------------------------------------------------------
Set v_Count_Formacao 			= GetSelectedCount([Formação]);
Set v_Count_Time 				= GetSelectedCount([Time Ilha]);
Set v_Formacao					= GetFieldSelections([Formação]);
Set v_Zn						= Subfield(GetFieldSelections([Formação]),'-',1);
Set v_Meio						= Subfield(GetFieldSelections([Formação]),'-',2);
Set v_Ataque					= Subfield(GetFieldSelections([Formação]),'-',3);
		
		
Set v_Goleiro					= ONLY({<Pos={'Go'}>}Jogadores);
Set v_Z1						= ONLY({<Pos={'Zn1'}>}Jogadores);
Set v_Z2						= ONLY({<Pos={'Zn2'}>}Jogadores);
Set v_Z3						= ONLY({<Pos={'Zn3'}>}Jogadores);
Set v_Z4						= ONLY({<Pos={'Zn4'}>}Jogadores);
Set v_Z5						= ONLY({<Pos={'Zn5'}>}Jogadores);
				
Set v_Meio1						= ONLY({<Pos={'Meio1'}>}Jogadores);
Set v_Meio2						= ONLY({<Pos={'Meio2'}>}Jogadores);
Set v_Meio3						= ONLY({<Pos={'Meio3'}>}Jogadores);
Set v_Meio4						= ONLY({<Pos={'Meio4'}>}Jogadores);
Set v_Meio5						= ONLY({<Pos={'Meio5'}>}Jogadores);
				
Set v_Ataque1					= ONLY({<Pos={'Ataque1'}>}Jogadores);
Set v_Ataque2					= ONLY({<Pos={'Ataque2'}>}Jogadores);
Set v_Ataque3					= ONLY({<Pos={'Ataque3'}>}Jogadores);