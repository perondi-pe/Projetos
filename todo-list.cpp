#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
#include <limits>

using namespace std;

vector<string> tarefas;

// limpa a tela do terminal
void limparTela() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void menu(){
    cout << "\n--- SISTEMA DE TAREFAS ---\n";
    cout << "1. Adicionar tarefa\n";
    cout << "2. Listar tarefas\n";
    cout << "3. Remover tarefa\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opcao: ";
}

void adicionarTarefa(){
    string tarefa;
    cout << "Digite a tarefa: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, tarefa);
    tarefas.push_back(tarefa);
    cout << "Tarefa adicionada com sucesso!\n";
}

void listarTarefas(){
    if(tarefas.empty()){
        cout << "\nNenhuma tarefa cadastrada.\n";
        return;
    }
    
    cout << "\n--- TAREFAS ---\n";
    for(int i = 0; i < tarefas.size(); i++){
        cout << i + 1 << ". " << tarefas[i] << "\n";
    }
}

void removerTarefa(){
    if(tarefas.empty()){
        cout << "\nNenhuma tarefa para remover.\n";
        return;
    }
    
    listarTarefas();
    int indice;
    cout << "\nDigite o numero da tarefa a remover: ";
    cin >> indice;
    
    if(indice > 0 && indice <= tarefas.size()){
        tarefas.erase(tarefas.begin() + indice - 1);
        cout << "Tarefa removida com sucesso!\n";
    } else {
        cout << "Opcao invalida!\n";
    }
}

void salvarTarefas(){
    ofstream arquivo("tarefas.txt");

    for(string tarefa : tarefas){
        arquivo << tarefa << endl;
    }

    arquivo.close();
}
void carregarTarefas(){
    ifstream arquivo("tarefas.txt");
    string tarefa;

    while(getline(arquivo, tarefa)){
        tarefas.push_back(tarefa);
    }

    arquivo.close();
}

int main(){
    carregarTarefas();
    int opcao;
    
    while(true){
        limparTela();
        menu();
        cin >> opcao;
        
        switch(opcao){
            case 1:
                adicionarTarefa();
                salvarTarefas();
                break;
            case 2:
                listarTarefas();
                break;
            case 3:
                removerTarefa();
                salvarTarefas();
                break;
            case 4:
                cout << "Encerrando o programa...\n";
                return 0;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
        
        cout << "\nPressione enter para continuar...";
        cin.ignore();
        cin.get();
    }
    
    return 0;
}
