# Fila de Banco Estática e Dinâmica - Estrutura de Dados

## Descrição do Problema
Em um cenário hipotético, o atendimento bancário é feito para duas categorias de clientes: atendimento normal e atendimento de prioridade. Assim, um sistema de controle de atendimento deve ser construído de modo a apresentar o seguinte funcionamento: O programa deve permitir o cadastro de 5 clientes em uma estrutura de FILA. Sendo 5 clientes na FILA de NORMAL e 5 clientes na FILA de PRIORIDADE. Os clientes são atendidos pelos mesmos caixas do banco, sendo sempre liberado 2 clientes da fila normal e 1 da fila de prioridade. O banco precisa de um sistema para este controle de atendimentos. A ideia é ter um programa que permita registrar os clientes e fazer a liberação dos mesmos para atendimento.

## Requisitos do Programa
Com base no problema exposto, crie um programa que atenda as necessidades do cenário descrito acima, considerando os seguintes requisitos: O programa deve ter os seguintes menus:
- CADASTRAR CLIENTES -> NORMAL: deve permitir o cadastro do nome dos clientes em uma estrutura FILA, com no máximo 5 clientes. Assim que 5 clientes forem cadastrados, o processo de cadastro deve ser bloqueado. O programa não deve permitir que nomes em branco sejam registrados.
- CADASTRAR CLIENTES -> PRIORIDADE: deve permitir o cadastro do nome dos clientes em uma estrutura FILA, com no máximo 5 clientes. Assim que 5 clientes forem cadastrados, o processo de cadastro deve ser bloqueado. O programa não deve permitir que nomes em branco sejam registrados.
- LIBERAR ATENDIMENTO: deve liberar 2 clientes da FILA NORMAL e 1 cliente da FILA PRIORIDADE, com um delay de 5 segundos entre eles. Caso uma das FILAS esteja sem clientes, mostre na tela “Sem clientes na fila de prioridade ou fila normal”. Se ambas as Filas estiverem vazias, emita a mensagem “Sem clientes para atendimento” e permita retornar ao menu principal.

## Tela de Atendimento Liberado
Clientes Atendimento Comum
- Atendimento ao cliente <nome> ou “Sem clientes aguardando”
- Atendimento ao cliente <nome> ou “Sem clientes aguardando”

Clientes Atendimento Prioridade
- Atendimento ao cliente <nome> ou “Sem clientes aguardando”

Deseja prosseguir(S/N)? Caso sim, repita a rotina. Caso não, retorne para o MENU.

## Atenção
- A rotina de cadastro deve inserir um cliente por vez. Após o cadastro de um cliente, perguntar “Deseja cadastrar outro cliente(S/N)?”. Caso sim, repita a rotina. Caso não, retorne para o menu principal.
- Lembre-se de checar se a FILA já não está com 5 clientes (função isFull).
- Para efeito de simulação, adote que cada cliente leva em torno de 5 segundos para ser atendido.
