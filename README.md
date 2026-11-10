# PSE em Ação - Sistema de Gestão de Ações de Saúde Escolar

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Ambiente](https://img.shields.io/badge/Ambiente-Terminal-lightgrey.svg)
![Instituição](https://img.shields.io/badge/Institui%C3%A7%C3%A3o-UNICESUMAR-green.svg)

**PSE em Ação** é uma aplicação computacional desenvolvida em linguagem C, executada em ambiente de terminal, criada para apoiar equipes de educação e saúde no planejamento, registro e acompanhamento das ações coletivas do **Programa Saúde na Escola (PSE)**. 

Este projeto foi desenvolvido como requisito da Atividade de Estudo Programada (AEP) do 2º semestre de 2026 para os cursos de Engenharia de Software e Análise e Desenvolvimento de Sistemas da Universidade Cesumar (UNICESUMAR).

---

## 👥 Equipe Desenvolvedora
* Ana Carolina Mestriner
* Gabriel Quintanilha
* Pedro Henrique Gardin Segantini da Silva

---

## 🎯 Objetivo do Projeto
Auxiliar na organização das atividades de promoção da saúde (com foco em saúde mental e outras temáticas do PSE) no ambiente escolar. A solução substitui registros dispersos em planilhas e formulários, centralizando o controle de ações planejadas, realizadas e canceladas. 

**⚠️ Importante (Limites Éticos):** O sistema foi desenhado para utilizar **apenas dados fictícios e informações coletivas**. Ele **não armazena** nomes, diagnósticos, prontuários, condições clínicas ou dados sensíveis individuais dos estudantes. O programa também não realiza diagnósticos, triagens ou prescrições médicas.

---

## ⚙️ Funcionalidades (Escopo do Sistema)

O sistema opera através de um menu principal interativo em loop e possui as seguintes funcionalidades:

1. **Cadastrar Ação:** Permite registrar uma ação informando código, escola, tema, data prevista, público-alvo, responsável, quantidade prevista de participantes e situação inicial.
2. **Listar Ações:** Apresenta todas as ações cadastradas no sistema de maneira estruturada.
3. **Pesquisar Ação:** Permite localizar ações específicas através de busca por Código, Escola ou Tema.
4. **Atualizar Situação:** Altera o status de uma ação (Planejada, Realizada ou Cancelada). Caso a ação seja marcada como "Realizada", o sistema solicita o registro da quantidade efetiva de participantes.
5. **Gerar Resumo:** Exibe um painel consolidado contendo:
   - Total de ações cadastradas.
   - Quantidade de ações por situação.
   - Total previsto vs. efetivo de participantes.
   - Percentual geral de participação.

*Nota: Os dados são armazenados na memória (utilizando Structs e Vetores) durante a execução e não são persistidos em banco de dados ou arquivos de texto nesta versão.*

---

## 💻 Como Compilar e Executar

### Pré-requisitos
* Sistema Operacional Windows.
* Compilador GCC instalado (ou ambientes como Dev-C++ / Code::Blocks) para compilar o código-fonte.
* Prompt de Comando (CMD) para execução ideal.

### Compilando a partir do código-fonte (via GCC)
1. Abra o terminal (Prompt de Comando).
2. Navegue até o diretório onde o arquivo `.c` está localizado:
   ```cmd
   cd caminho/para/a/pasta/do/projeto
   ```
3. Compile o código com o comando:
   ```cmd
   gcc -o PSE_Acao main.c
   ```
   *(Substitua `main.c` pelo nome exato do seu arquivo de código-fonte)*

### Executando o programa
Para garantir que o programa não feche abruptamente ao ser finalizado, execute-o diretamente pelo terminal:
1. No Prompt de Comando, no mesmo diretório do arquivo executável, digite:
   ```cmd
   PSE_Acao.exe
   ```
2. Pressione `Enter`. O menu principal do sistema será exibido.

---

## 📚 Documentação
A documentação completa do projeto, incluindo Contextualização, Diagramas de Casos de Uso, Requisitos Funcionais e Não Funcionais, Fluxogramas e o Manual do Usuário detalhado com capturas de tela, encontra-se no arquivo `PSE_em_Acao_Documento_Final.docx` (ou versão `.pdf`) armazenado na pasta de documentação deste repositório.
