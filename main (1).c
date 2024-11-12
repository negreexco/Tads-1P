#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTES 300

FILE *arquivo, *pastel;

void cabecalho() {
  printf("┌─────----------------- •✧✧• -----------------─────┐\n");
  printf("•       Bem-Vindo ao Sistema da C - PIZZARIA!      •\n");
  printf("•  Aceitamos PIX e cartões ELO, VISA e Mastercard  •\n");
  printf("└─────----------------- •✧✧• -----------------─────┘\n");
}

void entrada() {
  printf("┌─────----------------- •✧✧• -----------------─────┐\n");
  printf("•         VAMOS DAR INÍCIO AO SEU CADASTRO!        •\n");
  printf("└─────----------------- •✧✧• -----------------─────┘\n\n");
}

typedef struct {
  char nome[20];
  char sobrenome[20];
  char telefone[12];
  char cpf[12];
  int pagamento;
} CadastroCliente;

typedef struct {
  CadastroCliente clientes[MAX_CLIENTES];
  int quantidade;
} ListaClientes;

ListaClientes lista;

void adicionarClienteALista(ListaClientes *lista, CadastroCliente cliente) {
  if (lista->quantidade < MAX_CLIENTES) {
    lista->clientes[lista->quantidade] = cliente;
    lista->quantidade++;
  } else {
    printf("A lista de clientes está cheia.\n");
  }
}

CadastroCliente realizarCadastro(ListaClientes *lista) {
  CadastroCliente cliente;
  int opcaoAlteracao;
  FILE *arquivo;

  printf("\nCadastro Iniciado Com Sucesso!\n");
  printf("Digite seu nome: ");
  scanf("%s", cliente.nome);
  printf("Digite seu sobrenome: ");
  scanf("%s", cliente.sobrenome);
  printf("Digite seu telefone: ");
  scanf("%s", cliente.telefone);
  printf("Digite seu CPF: ");
  scanf("%s", cliente.cpf);
  printf("Formas de Pagamento:\n");
  printf("(1) Débito\n");
  printf("(2) Crédito\n");
  printf("(3) PIX\n");
  printf("(4) Dinheiro\n");
  printf("Digite a opção desejada: ");
  scanf("%d", &cliente.pagamento);
  printf("Deseja alterar algum dado de cadastro? (1) Sim / (2) Não: ");
  int opcao;
  scanf("%d", &opcao);
  if (opcao == 1) {
    printf("Qual dado você deseja alterar?\n");
    printf("(1) Nome\n");
    printf("(2) Sobrenome\n");
    printf("(3) Telefone\n");
    printf("(4) CPF\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcaoAlteracao);

    switch (opcaoAlteracao) {
    case 1:
      printf("Digite o novo nome: ");
      scanf("%s", cliente.nome);
      break;
    case 2:
      printf("Digite o novo sobrenome: ");
      scanf("%s", cliente.sobrenome);
      break;
    case 3:
      printf("Digite o novo telefone: ");
      scanf("%s", cliente.telefone);
      break;
    case 4:
      printf("Digite o novo CPF: ");
      scanf("%s", cliente.cpf);
      break;
    default:
      printf("Opção inválida.\n");
    }
  }
  adicionarClienteALista(lista, cliente);
  pastel = fopen("quantidade.txt", "w");
  fprintf(pastel, "%d", lista->quantidade);
  fclose(pastel);

  arquivo = fopen("dados.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
  } else {
    fprintf(arquivo, "Nome: %s\n", cliente.nome);
    fprintf(arquivo, "Sobrenome: %s\n", cliente.sobrenome);
    fprintf(arquivo, "Telefone: %s\n", cliente.telefone);
    fprintf(arquivo, "CPF: %s\n", cliente.cpf);
    fprintf(arquivo, "Forma de pagamento: %d\n", cliente.pagamento);
    fprintf(arquivo, "\n");
  }
  fclose(arquivo);

  return cliente;
}

void imprimirPessoas() {
  char max[300];
  printf("\n%d.\n", lista.quantidade);
  int i;
  arquivo = fopen("dados.txt", "r");
  for (i = 0; i < lista.quantidade * 5; i++) {
    fgets(max, 300, arquivo);
    printf("%s", max);
  }
  fclose(arquivo);
}


void buscarCliente(ListaClientes *lista) {
   
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  system("clear");

  int i;
  for (i = 0; i < 100; i++) {
    if (strcmp(cpf, lista->clientes[i].cpf) == 0) {
      arquivo = fopen ("dados.csv", "r");
      printf("Cliente encontrado:\n");
      printf("Nome: %s\n", lista->clientes[i].nome);
      printf("Sobrenome: %s\n", lista->clientes[i].sobrenome);
      printf("Telefone: %s\n", lista->clientes[i].telefone);
      printf("CPF: %s\n", lista->clientes[i].cpf);
      printf("Forma de pagamento: %d\n", lista->clientes[i].pagamento);
      int opcao;
      printf("\nDeseja alterar os dados do cliente? (1 - Sim, 0 - Não): ");
      scanf("%d", &opcao);

      if (opcao == 1) {
        arquivo = fopen("dados.txt", "a");
        printf("\nDigite o novo nome do cliente: ");
        scanf("%s", lista->clientes[i].nome);

        printf("Digite o novo sobrenome do cliente: ");
        scanf("%s", lista->clientes[i].sobrenome);

        printf("Digite o novo telefone do cliente: ");
        scanf("%s", lista->clientes[i].telefone);

        printf("Digite a nova forma de pagamento do cliente: ");
        scanf("%d", &lista->clientes[i].pagamento);

        printf("\nDados do cliente alterados com sucesso!\n");
      }
      fclose(arquivo);
      return;
    }
  }

  printf("Cliente com CPF %s não encontrado.\n", cpf);
}



void menuAdministrador(ListaClientes *lista) {
  int opcao;

  do {
    printf("\n(1) Cadastrar cliente\n");
    printf("(2) Buscar cliente\n");
    printf("(3) Imprimir todos os clientes\n");
    printf("(0) Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      realizarCadastro(lista);
      break;
    case 2:
      buscarCliente(lista);
      break;
    case 3:
      imprimirPessoas();
      break;
    case 0:
      printf("Saindo do modo administrador...\n");
      break;
    default:
      printf("Opção inválida.\n");
    }
  } while (opcao != 0);
}

void lertxt(CadastroCliente cliente[], int *quantidade) {
  FILE *arquivo = fopen("dados.txt", "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  char linha[200];
  *quantidade = 0;

  fgets(linha, 200, arquivo);

  while (fgets(linha, 200, arquivo) != NULL) {
    char *token = strtok(linha, ",");

    if (token == NULL) {
      continue;
    }

    strcpy(cliente[*quantidade].nome, token);
    token = strtok(NULL, ",");

    if (token == NULL) {
      continue;

      if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo 'dados.txt'. Verifique se o arquivo "
               "existe.\n");
        return;
      }
    }

    strcpy(cliente[*quantidade].sobrenome, token);
    token = strtok(NULL, ",");

    if (token == NULL) {
      continue;
    }

    strcpy(cliente[*quantidade].telefone, token);
    token = strtok(NULL, ",");

    if (token == NULL) {
      continue;
    }

    strcpy(cliente[*quantidade].cpf, token);
    token = strtok(NULL, ",");

    if (token == NULL) {
      continue;
    }

    (*quantidade)++;
  }

  fclose(arquivo);
}

void iniciopedido() {
  system("clear");
  printf("┌─────----------------- •✧✧• -----------------─────┐\n");
  printf("•         VAMOS DAR INÍCIO AO SEU PEDIDO!          •\n");
  printf("└─────----------------- •✧✧• -----------------─────┘\n\n");
}

void sequenciapedido() {
  system("clear");
  printf("┌─────----------------- •✧✧• -----------------─────┐\n");
  printf("•     ESTAMOS QUASE LÁ! AGORA SÓ FALTA A BEBIDA.   •\n");
  printf("└─────----------------- •✧✧• -----------------─────┘\n\n");
}

typedef struct {
  int codigo;
  char nome[50];
  float preco;
} ItemMenuPizzas;

ItemMenuPizzas cardapio_pizzas[] = {
    {1, "4 queijos", 15.90},                              {2, "Bacon", 16.90},
    {3, "Calabresa", 16.90},                              {4, "Frango", 16.90},
    {5, "Marguerita", 16.90}, 
    {6, "Portuguesa", 17.90},
    {7, "Vegetariana", 17.90}, 
    {8, "Banana", 15.90},
    {9, "Chocolate", 16.90},   
    {10, "Romeu e julieta", 17.90}};

typedef struct {
  int codigo;
  char nome[50];
  float preco;
} ItemMenuBebidas;

ItemMenuBebidas cardapio_bebidas[] = {
    {1, "Água sem gás - 500ml", 2.90},
    {2, "Água com gás - 500ml", 3.90},
    {3, "H2O Limão- 500ml", 5.90},
    {4, "H2O Limoneto- 500ml", 5.90},
    {5, "Refrigerante coca-cola - Lata", 4.90},
    {6, "Refrigerante Guaraná - Lata", 4.90},
    {7, "Refrigerante Fanta-Laranja - Lata", 4.90},
};

float calcularTotal(float total_pizzas, float total_bebidas) {
  return total_pizzas + total_bebidas;
}

void exibirPedido(float total_pizzas, float total_bebidas, float total_pedido) {
  printf("┌─────----------------- •✧✧• -----------------─────┐\n");
  printf("•                   RESUMO DO PEDIDO              •\n");
  printf("└─────----------------- •✧✧• -----------------─────┘\n\n");
  printf("• Pizzas: R$ %.2f\n", total_pizzas);
  printf("• Bebidas: R$ %.2f\n", total_bebidas);
  printf("• Total do pedido: R$ %.2f\n", total_pedido);
  printf("└─────----------------- •✧✧• -----------------─────┘\n");
}

void salvarPedido(float total_pizzas, float total_bebidas, float total_pedido) {
  FILE *arquivo;
  char nome_arquivo[100];

  printf("\nDigite o nome do arquivo para salvar o pedido: ");
  scanf("%s", nome_arquivo);

  arquivo = fopen(nome_arquivo, "a");

  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo.\n");
    return;
  }

  fprintf(arquivo, "┌─────----------------- •✧✧• -----------------─────┐\n");
  fprintf(arquivo, "•                  EXTRATO DO PEDIDO               •\n");
  fprintf(arquivo, "└─────----------------- •✧✧• -----------------─────┘\n\n");

  fprintf(arquivo, "• Pizzas: R$ %.2f\n", total_pizzas);
  fprintf(arquivo, "• Bebidas: R$ %.2f\n", total_bebidas);
  fprintf(arquivo, "• Total do pedido: R$ %.2f\n", total_pedido);
  fprintf(arquivo, "└─────----------------- •✧✧• -----------------─────┘\n\n");
  printf("\nPedido salvo com sucesso no arquivo %s.\n", nome_arquivo);
  fclose(arquivo);
}

void realizarPedido() {
  int opcao, quantidade;
  float total_pizzas = 0.0, total_bebidas = 0.0, total_pedido = 0.0;
  int continuar;

  do {
    printf("┌────────────────---─── •✧✧• ─---──────────────────┐\n");
    printf("•             PIZZAS (Salgadas e Doces)            •\n");
    printf("└─────────────────---── •✧✧• ─---──────────────────┘\n\n");
    for (int i = 0; i < sizeof(cardapio_pizzas) / sizeof(cardapio_pizzas[0]);
         i++) {
      printf("• %d. %s ...................R$ %.2f\n", cardapio_pizzas[i].codigo,
             cardapio_pizzas[i].nome, cardapio_pizzas[i].preco);
    }
    printf("└─────----------------- •✧✧• -----------------─────┘\n\n");

    printf("Selecione a pizza desejada: ");
    scanf("%d", &opcao);

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    total_pizzas += cardapio_pizzas[opcao - 1].preco * quantidade;

    printf("\nDeseja adicionar mais uma PIZZA? (1) Sim / (2) Não): ");
    scanf(" %d", &continuar);
  } while (continuar == 1);

  if (total_pizzas > 0) {
    sequenciapedido();
    do {
      printf("┌─────----------------- •✧✧• -----------------─────┐\n");
      printf("•               ÁGUA E REFRIGERANTES               •\n");
      printf("└─────----------------- •✧✧• -----------------─────┘\n\n");
      for (int i = 0;
           i < sizeof(cardapio_bebidas) / sizeof(cardapio_bebidas[0]); i++) {
        printf("• %d. %s ...................R$ %.2f\n",
               cardapio_bebidas[i].codigo, cardapio_bebidas[i].nome,
               cardapio_bebidas[i].preco);
      }
      printf("└─────----------------- •✧✧• -----------------─────┘\n\n");

      printf("Selecione a bebida desejada: ");
      scanf("%d", &opcao);

      printf("Quantidade: ");
      scanf("%d", &quantidade);

      total_bebidas += cardapio_bebidas[opcao - 1].preco * quantidade;

      printf("\nDeseja adicionar mais uma BEBIDA? (1) Sim / (2) Não): ");
      scanf(" %d", &continuar);
    } while (continuar == 1);
  }

  total_pedido = calcularTotal(total_pizzas, total_bebidas);
  exibirPedido(total_pizzas, total_bebidas, total_pedido);

  salvarPedido(total_pizzas, total_bebidas, total_pedido);
}

int main() {
  int opcao, opcaomenu, num;
  CadastroCliente clientes[100];
  int quantidade, b;
  char a[4];
  lertxt(clientes, &quantidade);

  pastel = fopen("quantidade.txt", "r");
  fgets(a, 4, pastel);
  b = atoi(a);
  fclose(pastel);

  lista.quantidade = b;

  float total_pedido, total_pizzas, total_bebidas;
  cabecalho();

  printf("\n(1) CLIENTE (2) ADMINISTRADOR \n");
  printf("\nQual opção desejada: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    entrada();
    CadastroCliente cliente = realizarCadastro(&lista);
    system("clear");

    do {
      printf("\n(1) Realizar Pedido\n");
      printf("\n(0) Sair\n");
      printf("\nEscolha uma opção: ");
      scanf("%d", &opcaomenu);

      switch (opcaomenu) {
      case 1:
        iniciopedido();
        realizarPedido();
        break;
      case 0:
        
        printf("\n\nSaindo...\n");
        system("clear");
        break;
      default:
        printf("\nOpção inválida. Tente novamente.\n");
      }
    } while (opcaomenu != 0);
  } else {
    int senha;
    printf("\nDigite a senha: ");
    scanf("%d", &senha);
    if (senha == 12345) {
      menuAdministrador(&lista);
    }
  }

  return 0;
}
