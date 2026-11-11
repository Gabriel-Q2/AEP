# PSE em Ação - Sistema de Gestão de Ações de Saúde Escolar

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Ambiente](https://img.shields.io/badge/Ambiente-Terminal-lightgrey.svg)
![Instituição](https://img.shields.io/badge/Institui%C3%A7%C3%A3o-UNICESUMAR-green.svg)


Sistema em C, feito para rodar no terminal, para gerenciar as ações do Programa Saúde na Escola (PSE).

Projeto da AEP do 2º semestre de 2026, para os cursos de Engenharia de Software e Análise e Desenvolvimento de Sistemas da UNICESUMAR.

## Sobre o projeto

A ideia é ajudar equipes de educação e saúde a planejar, registrar e acompanhar as ações coletivas do PSE, principalmente as de saúde mental, mas também as de outros temas do programa. Em vez de planilhas e formulários espalhados, o sistema reúne tudo em um só lugar e mostra o que está planejado, o que já foi realizado e o que foi cancelado.

Um ponto importante: o programa trabalha só com dados fictícios e informações coletivas. Ele não guarda nome, diagnóstico, prontuário nem qualquer dado individual de estudante, e também não faz diagnóstico, triagem ou prescrição.

## Funcionalidades

Ao abrir, o programa mostra um menu que fica em loop até o usuário sair. As opções são:

1. *Cadastrar ação*: registra código, escola, tema, data prevista, público-alvo, responsável, quantidade prevista de participantes e a situação inicial.
2. *Listar ações*: mostra todas as ações cadastradas.
3. *Pesquisar ação*: busca por código, escola ou tema.
4. *Atualizar situação*: muda o status da ação para Planejada, Realizada ou Cancelada. Se for marcada como Realizada, o sistema pede a quantidade real de participantes.
5. *Gerar resumo*: mostra o total de ações, quantas há em cada situação, participantes previstos x efetivos e o percentual geral de participação.

Os dados ficam só na memória (structs e vetores) enquanto o programa está aberto. Nesta versão não há banco de dados nem gravação em arquivo, então tudo se perde ao fechar.

## Como compilar e executar

### O que você precisa

- Windows
- GCC instalado (Dev-C++ e Code::Blocks também servem para compilar)
- Prompt de Comando (CMD)

### Compilando

No CMD, entre na pasta do projeto e compile:

cmd
cd caminho\para\a\pasta\do\projeto
gcc -o PSE_Acao main.c


Troque main.c pelo nome do seu arquivo-fonte, se for diferente.

### Executando

Rode pelo próprio CMD, na mesma pasta do executável. Se abrir com duplo clique, a janela fecha assim que o programa termina.

cmd
PSE_Acao.exe


## Documentação

O documento completo está na pasta de documentação do repositório, em PSE_em_Acao_Documento_Final.docx (ou na versão .pdf). Ele traz a contextualização, os diagramas de casos de uso, os requisitos funcionais e não funcionais, os fluxogramas e o manual do usuário com capturas de tela.

## Equipe

- Ana Carolina Mestriner
- Gabriel Quintanilha
- Pedro Henrique Gardin Segantini da Silva
