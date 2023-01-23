#include<iostream>
#include<ctime>
char t[3][3];
int i,j;
char player = 'X';
char computer = 'O';
int cheekTable();
char cheekWinner();
void affichage();
int main()
{
    affichage();
    srand(time(0));
    do
    {
        do
        {
           std::cout<<"entrer les cordonnes de ligne #: ";
           std::cin>>i;
           std::cout<<"entrer les cordonnes de colonne #: ";
           std::cin>>j;
           i--;
           j--;
        } while (t[i][j] != '\0');
        t[i][j] = player;
        affichage();
        if(cheekWinner()==player){
             std::cout<<"you win !!\n";
             break;
        }
       else if(cheekWinner()==computer){
            std::cout<<"you lose !!\n";
            break;
            }
            else{
                if(cheekTable()==0){
                    std::cout<<"it is a tie\n";
                    break;
                }

            }

        do
        {
            i = rand() % 3;
            j = rand() % 3;

        } while (t[i][j] != '\0');
        t[i][j] = computer;
        affichage();
        if(cheekWinner()==player){
            std::cout<<"you win !!\n";
            break;
        }
        else if(cheekWinner()==computer){
            std::cout<<"you lose !!\n";
            break;
        }
            
        }while(cheekTable!=0);
        
        return 0;
    }

int cheekTable(){
        int c;
        c=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(t[i][j]=='\0')//ori i3mr
                    c++;
            }
    }
    return c;
}
char cheekWinner(){
    for(i=0;i<3;i++){
        if(t[i][0]==t[i][1] && t[i][0]==t[i][2]&& t[i][0]!='\0'){
            if(t[i][0]==player){
                return player;
                }
            else{
                return computer;
                }
            }
        else if(t[0][i]==t[1][i] && t[0][i]==t[2][i] && t[0][i]!='\0'){
            if(t[0][i]==player){
                return player;
                }
            else{
                return computer;
                }
            }
        }
    if(((t[0][0]==t[1][1]&&t[0][0]==t[2][2])||(t[0][2]==t[1][1]&&t[0][2]==t[2][0]))&&t[1][1]!='\0'){
        if(t[1][1]==player){
            return player;
        }
        else{
           return computer;
        }
    }
    return 0;
}
void affichage(){
        std::cout<<t[0][0]<<"\t| "<<t[0][1]<<"\t| "<<t[0][2]<<"\n";
        std::cout<<"------------------------\n";
        std::cout<<t[1][0]<<"\t| "<<t[1][1]<<"\t| "<<t[1][2]<<'\n';
        std::cout<<"------------------------\n";
        std::cout<<t[2][0]<<"\t| "<<t[2][1]<<"\t| "<<t[2][2]<<"\n\n\n\n\n";
}
