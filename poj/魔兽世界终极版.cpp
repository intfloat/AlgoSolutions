#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<iomanip>
#include<cstring>
using namespace std;
int life[5],attackpower[5]; 
int hour,minute; 
char weapon[3][10]={"sword","bomb","arrow"};
char Standard[5][10]={"dragon","ninja","iceman","lion","wolf"};
char redorder[5][10]={"iceman","lion","wolf","ninja","dragon"};
char blueorder[5][10]={"lion","dragon","ninja","iceman","wolf"};
int RedNumOrder[5]={2,3,4,1,0};
int BlueNumOrder[5]={3,0,1,2,4}; 
class City{
    public:
        int life;   
        int warrior;        
        int RedNum;     
        bool redshot;
        bool redbomb;
        char redwar[10];         
        int BlueNum;
        bool blueshot;
        bool bluebomb;
        char bluewar[10];
        int redwin;
        int bluewin;
        bool ifredwin;
        bool ifbluewin;
        bool HaveFlag;  
        char flag[5];    
        City(){HaveFlag=false; life=0; warrior=0; 
            redshot=false; blueshot=false; 
            redbomb=false; bluebomb=false; 
            redwin=0; bluewin=0; 
            ifredwin=false; ifbluewin=false;}
};
class blueheadquarter;
class Record{
    public:
        int n;
        bool Alive; 
        char Variety[10];       
        int position;        
        int nowlife;    
        int attack; 
        bool bomb;              
        bool sword; 
        bool shot;      
        double spirit;  
        int arrow;  
        int ArrowPower; 
        int SwordPower;     
        int step;       
        int loyalty;    
        int dec;        
        Record(){step=0;}
};
class redheadquarter{
    private:                
        char Mark[20];      
    public:
        int number;
        int totallife;      
        int EnemyNumber;        
        int WarNum; 
        Record record[5000];        
        redheadquarter(int M){
            totallife=M; EnemyNumber=0;
            strcpy(Mark,"redheadquarter");
            WarNum=1;
        }
        int MakeWarrior();
        int LionRun();
        int March();
        int WarriorArrow(blueheadquarter& Blue);
        int BombDeath(blueheadquarter& Blue);
        int ReportLife();
        int ReportWeapon();
        int Fight(blueheadquarter& Blue);
};
class blueheadquarter{
    private:            
        char Mark[20];      
    public:
        int number;
        int totallife;  
        int EnemyNumber;
        int WarNum;
        Record record[5000];
        blueheadquarter(int M){
            totallife=M; EnemyNumber=0;
            strcpy(Mark,"blueheadquarter");
            WarNum=1;
        }
        int MakeWarrior();
        int LionRun();
        int March();
        int WarriorArrow(redheadquarter& Red);
        int BombDeath();
        int ReportLife();
        int ReportWeapon();
};
int total,TotalLife,nCity,ArrowPower,DecLoyalty,TotalTime;
int BlueEnemyNumber,RedEnemyNumber;
City *city;
int PrintMarch( redheadquarter& Red,blueheadquarter& Blue);
int produce();
int acquire(redheadquarter& Red, blueheadquarter& Blue);
int ShowArrow(redheadquarter& Red, blueheadquarter& Blue);
int main(){
    cin>>total;
    for(int k=0;k<total;k++){   
        cin>>TotalLife>>nCity>>ArrowPower>>DecLoyalty>>TotalTime;
        delete []city;
        city=new City[nCity+2];
        for(int i=0;i<nCity+2;i++){
            city[i].BlueNum=0; city[i].RedNum=0;
            city[i].redwar[0]='\0'; city[i].bluewar[0]='\0';
            city[i].flag[0]='\0';
        }
        redheadquarter Red(TotalLife),*tmp1;
        tmp1=&Red;
        Red.number=0;
        blueheadquarter Blue(TotalLife),*tmp2;
        tmp2=&Blue;
        Blue.number=0;
        BlueEnemyNumber=0; RedEnemyNumber=0;
        for(int i=0;i<5;i++)
            cin>>life[i];
        for(int i=0;i<5;i++)
            cin>>attackpower[i];
        cout<<"Case "<<k+1<<":"<<endl;
        for(int i=0;i<=TotalTime;i++){
            hour=i/60;
            minute=i%60;
            if(minute==0){
                Red.MakeWarrior();
                Blue.MakeWarrior();
            }
            else if(minute==5){
                Red.LionRun();
                Blue.LionRun();
            }
            else if(minute==10){                
                Red.March();
                Blue.March();
                PrintMarch(Red,Blue);
                if(RedEnemyNumber>=2||BlueEnemyNumber>=2)
                    break;
            }
            else if(minute==20){
                produce();
            }
            else if(minute==30){
                acquire(Red,Blue);
            }
            else if(minute==35){
                Red.WarriorArrow(Blue);
                Blue.WarriorArrow(Red);
                ShowArrow(Red,Blue);
            }
            else if(minute==38){
                Red.BombDeath(Blue);                
            }
            else if(minute==40){
                Red.Fight(Blue);                
            }
            else if(minute==50){
                Red.ReportLife();
                Blue.ReportLife();
            }
            else if(minute==55){
                Red.ReportWeapon();
                Blue.ReportWeapon();
            }           
        }           
    }   
    return 0;
} 
int redheadquarter::MakeWarrior(){
    if(number==5)
        number=0;
    int i=number;   
    if(totallife<life[RedNumOrder[i]])
        return 0;
    else if(totallife>=life[RedNumOrder[i]]){
        record[WarNum].n=WarNum;
        record[WarNum].position=0;
        strcpy(record[WarNum].Variety,redorder[i]);
        record[WarNum].Alive=true;
        number++;
        totallife-=life[RedNumOrder[i]];
        printf("%03d:%02d red %s %d born\n",hour,minute,redorder[i],WarNum);
        if(strcmp(redorder[i],"dragon")==0){        
            record[WarNum].attack=attackpower[0];           
            record[WarNum].nowlife=life[0];     
            if(strcmp(weapon[WarNum%3],"sword")==0){                
                record[WarNum].sword=true;          
                record[WarNum].SwordPower=record[WarNum].attack/5;
            }
            else{           
                record[WarNum].sword=false;
            }
            if(strcmp(weapon[WarNum%3],"arrow")==0){            
                record[WarNum].arrow=3;             
                record[WarNum].ArrowPower=ArrowPower;
            }
            else{               
                record[WarNum].arrow=0;
            }                   
            if(strcmp(weapon[WarNum%3],"bomb")==0){         
                record[WarNum].bomb=true;
            }
            else{               
                record[WarNum].bomb=false;
            }               
            record[WarNum].spirit=totallife*1.0/life[RedNumOrder[i]];
            cout<<"Its morale is "<<fixed<<setprecision(2)<<record[WarNum].spirit<<endl;
        }
        else if(strcmp(redorder[i],"lion")==0){     
            record[WarNum].loyalty=totallife;           
            record[WarNum].attack=attackpower[3];           
            record[WarNum].dec=DecLoyalty;          
            record[WarNum].nowlife=life[3];     
            cout<<"Its loyalty is "<<totallife<<endl;
        }
        else if(strcmp(redorder[i],"iceman")==0){           
            record[WarNum].nowlife=life[2];         
            record[WarNum].step=0;      
            record[WarNum].attack=attackpower[2];
            if(strcmp(weapon[WarNum%3],"sword")==0){                
                record[WarNum].sword=true;              
                record[WarNum].SwordPower=record[WarNum].attack/5;
            }
            else{           
                record[WarNum].sword=false;
            }
            if(strcmp(weapon[WarNum%3],"arrow")==0){            
                record[WarNum].arrow=3;             
                record[WarNum].ArrowPower=ArrowPower;
            }
            else{               
                record[WarNum].arrow=0;
            }                   
            if(strcmp(weapon[WarNum%3],"bomb")==0){
                record[WarNum].bomb=true;               
            }
            else{               
                record[WarNum].bomb=false;
            }
        }
        else if(strcmp(redorder[i],"wolf")==0){         
            record[WarNum].bomb=false;          
            record[WarNum].sword=false;         
            record[WarNum].arrow=0;         
            record[WarNum].attack=attackpower[4];           
            record[WarNum].nowlife=life[4];         
        }
        else if(strcmp(redorder[i],"ninja")==0){
            record[WarNum].nowlife=life[1];         
            record[WarNum].attack=attackpower[1];
            if(strcmp(weapon[WarNum%3],"sword")==0||strcmp(weapon[(WarNum+1)%3],"sword")==0){               
                record[WarNum].sword=true;              
                record[WarNum].SwordPower=record[WarNum].attack/5;
            }
            else{               
                record[WarNum].sword=false;
            }
            if(strcmp(weapon[WarNum%3],"arrow")==0||strcmp(weapon[(WarNum+1)%3],"arrow")==0){               
                record[WarNum].arrow=3;             
                record[WarNum].ArrowPower=ArrowPower;
            }
            else{               
                record[WarNum].arrow=0;
            }                   
            if(strcmp(weapon[WarNum%3],"bomb")==0||strcmp(weapon[(WarNum+1)%3],"bomb")==0){             
                record[WarNum].bomb=true;
            }
            else{               
                record[WarNum].bomb=false;
            }
        }
        WarNum++;
        return 0;
    }
    return 0;
}
int blueheadquarter::MakeWarrior(){ 
    if(number==5)
        number=0;
    int i=number;   
    if(totallife<life[BlueNumOrder[i]])
        return 0;
    else if(totallife>=life[BlueNumOrder[i]]){
        record[WarNum].n=WarNum;
        record[WarNum].position=nCity+1;        
        strcpy(record[WarNum].Variety,blueorder[i]);
        record[WarNum].Alive=true;
        number++;
        totallife-=life[BlueNumOrder[i]];
        printf("%03d:%02d blue %s %d born\n",hour,minute,blueorder[i],WarNum);
        if(strcmp(blueorder[i],"dragon")==0){       
            record[WarNum].attack=attackpower[0];           
            record[WarNum].nowlife=life[0];     
            if(strcmp(weapon[WarNum%3],"sword")==0){                
                record[WarNum].sword=true;              
                record[WarNum].SwordPower=record[WarNum].attack/5;
            }
            else{               
                record[WarNum].sword=false;
            }
            if(strcmp(weapon[WarNum%3],"arrow")==0){            
                record[WarNum].arrow=3;         
                record[WarNum].ArrowPower=ArrowPower;
            }
            else{           
                record[WarNum].arrow=0;
            }               
            if(strcmp(weapon[WarNum%3],"bomb")==0){             
                record[WarNum].bomb=true;
            }
            else{               
                record[WarNum].bomb=false;
            }           
            record[WarNum].spirit=totallife*1.0/life[BlueNumOrder[i]];
            cout<<"Its morale is "<<fixed<<setprecision(2)<<record[WarNum].spirit<<endl;
        }
        else if(strcmp(blueorder[i],"lion")==0){            
            record[WarNum].loyalty=totallife;           
            record[WarNum].attack=attackpower[3];           
            record[WarNum].dec=DecLoyalty;      
            record[WarNum].nowlife=life[3];         
            cout<<"Its loyalty is "<<totallife<<endl;       
        }
        else if(strcmp(blueorder[i],"iceman")==0){      
            record[WarNum].nowlife=life[2];     
            record[WarNum].step=0;          
            record[WarNum].attack=attackpower[2];
            if(strcmp(weapon[WarNum%3],"sword")==0){                
                record[WarNum].sword=true;              
                record[WarNum].SwordPower=record[WarNum].attack/5;
            }
            else{           
                record[WarNum].sword=false;
            }
            if(strcmp(weapon[WarNum%3],"arrow")==0){
                record[WarNum].arrow=3;             
                record[WarNum].ArrowPower=ArrowPower;
            }
            else{                   
                record[WarNum].arrow=0;
            }               
            if(strcmp(weapon[WarNum%3],"bomb")==0){         
                record[WarNum].bomb=true;
            }
            else{               
                record[WarNum].bomb=false;
            }
        }
        else if(strcmp(blueorder[i],"wolf")==0){            
            record[WarNum].bomb=false;          
            record[WarNum].sword=false;         
            record[WarNum].arrow=0;     
            record[WarNum].attack=attackpower[4];       
            record[WarNum].nowlife=life[4];         
        }
        else if(strcmp(blueorder[i],"ninja")==0){           
            record[WarNum].nowlife=life[1];     
            record[WarNum].attack=attackpower[1];
            if(strcmp(weapon[WarNum%3],"sword")==0||strcmp(weapon[(WarNum+1)%3],"sword")==0){               
                record[WarNum].sword=true;              
                record[WarNum].SwordPower=record[WarNum].attack/5;
            }
            else{           
                record[WarNum].sword=false;
            }
            if(strcmp(weapon[WarNum%3],"arrow")==0||strcmp(weapon[(WarNum+1)%3],"arrow")==0){           
                record[WarNum].arrow=3;         
                record[WarNum].ArrowPower=ArrowPower;
            }
            else{               
                record[WarNum].arrow=0;
            }               
            if(strcmp(weapon[WarNum%3],"bomb")==0||strcmp(weapon[(WarNum+1)%3],"bomb")==0){
                record[WarNum].bomb=true;               
            }
            else{
                record[WarNum].bomb=false;              
            }
        }
        WarNum++;   
        return 0;
    }
    return 0;
}
int redheadquarter::LionRun(){
    for(int i=1;i<WarNum;i++){
        if(strcmp(record[i].Variety,"lion")==0&&record[i].Alive==true&&record[i].loyalty<=0){
            record[i].Alive=false;
            record[i].nowlife=-1;
            printf("%03d:%02d red lion %d ran away\n",hour,minute,i);
        }
    }
    return 0; 
}
int blueheadquarter::LionRun(){
    for(int i=1;i<WarNum;i++){
        if(strcmp(record[i].Variety,"lion")==0&&record[i].Alive==true&&record[i].loyalty<=0){
            record[i].Alive=false;
            record[i].nowlife=-1;
            printf("%03d:%02d blue lion %d ran away\n",hour,minute,i);
        }
    }
    return 0; 
}
int redheadquarter::March(){
    city[nCity+1].RedNum=0;
    for(int i=1;i<WarNum;i++){
        if(record[i].Alive==true&&record[i].nowlife>0&&record[i].position!=nCity+1){
            record[i].step++;       
            record[i].position++;
            if(record[i].position==nCity+1)
                BlueEnemyNumber++;
            city[record[i].position].RedNum=i;      
            city[record[i].position-1].RedNum=0;                
            strcpy(city[record[i].position].redwar,record[i].Variety);
        }
    }
    return 0;
}
int blueheadquarter::March(){
    city[0].BlueNum=0;  
    for(int i=1;i<WarNum;i++){  
        if(record[i].Alive==true&&record[i].nowlife>0&&record[i].position>0){
            record[i].step++;       
            record[i].position--;
            if(record[i].position==0)
                RedEnemyNumber++;
            city[record[i].position].BlueNum=i;      
            city[record[i].position+1].BlueNum=0;       
            strcpy(city[record[i].position].bluewar,record[i].Variety);     
        }
    }
    return 0;
}
int PrintMarch( redheadquarter& Red,blueheadquarter& Blue){
    char tmp[10];
    int n,m;
    for(int i=0;i<=nCity+1;i++){
        n=city[i].RedNum; m=city[i].BlueNum;
        if(Blue.record[m].nowlife<=0){Blue.record[m].Alive=false;}
        if(Red.record[n].nowlife<=0){Red.record[n].Alive=false;}
        if(i==0&&city[i].BlueNum!=0&&Blue.record[m].nowlife>0){
            printf("%03d:%02d blue %s %d reached red headquarter with ",hour,minute,Blue.record[m].Variety,city[i].BlueNum);
            strcpy(tmp,Blue.record[m].Variety);
            if(strcmp(tmp,"dragon")==0)
                printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
            else if(strcmp(tmp,"lion")==0)
                printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
            else if(strcmp(tmp,"iceman")==0){           
                if(Blue.record[m].nowlife>9&&Blue.record[m].step%2==0){
                    Blue.record[m].nowlife-=9;                  
                    Blue.record[m].attack+=20;                  
                }
                else if((Blue.record[m].nowlife)<=9&&(Blue.record[m].step)%2==0){
                    Blue.record[m].nowlife=1;
                    Blue.record[m].attack+=20;
                }
                printf("%d elements and force %d\n",Blue.record[m].nowlife,Blue.record[m].attack);              
            }
            else if(strcmp(tmp,"ninja")==0)
                printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
            else if(strcmp(tmp,"wolf")==0)
                printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
            if(RedEnemyNumber>=2)
                printf("%03d:%02d red headquarter was taken\n",hour,minute);        
        }
        else if(i==nCity+1&&city[i].RedNum!=0&&Red.record[n].nowlife>0){
            printf("%03d:%02d red %s %d reached blue headquarter with ",hour,minute,Red.record[city[i].RedNum].Variety,city[i].RedNum);
            strcpy(tmp,Red.record[city[i].RedNum].Variety);
            if(strcmp(tmp,"dragon")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            else if(strcmp(tmp,"lion")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            else if(strcmp(tmp,"iceman")==0){           
                if(Red.record[n].nowlife>9&&Red.record[n].step%2==0){
                    Red.record[n].nowlife-=9;               
                    Red.record[n].attack+=20;
                }
                else if((Red.record[n].nowlife)<=9&&(Red.record[n].step)%2==0){
                    Red.record[n].nowlife=1;
                    Red.record[n].attack+=20;
                }
                printf("%d elements and force %d\n",Red.record[n].nowlife,Red.record[n].attack);
            }
            else if(strcmp(tmp,"ninja")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            else if(strcmp(tmp,"wolf")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            if(BlueEnemyNumber>=2)
                printf("%03d:%02d blue headquarter was taken\n",hour,minute);
        }
        if(i!=0&&i!=nCity+1){
            if(city[i].RedNum!=0&&Red.record[city[i].RedNum].nowlife>0){
                printf("%03d:%02d red %s %d marched to city %d with ",hour,minute,Red.record[city[i].RedNum].Variety,city[i].RedNum,i);
            strcpy(tmp,Red.record[city[i].RedNum].Variety);
            if(strcmp(tmp,"dragon")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            else if(strcmp(tmp,"lion")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            else if(strcmp(tmp,"iceman")==0){           
                if((Red.record[n].nowlife)>9&&(Red.record[n].step)%2==0){               
                    Red.record[n].nowlife-=9;                       
                    Red.record[n].attack+=20;
                }
                else if((Red.record[n].nowlife)<=9&&(Red.record[n].step)%2==0){
                    Red.record[n].nowlife=1;
                    Red.record[n].attack+=20;
                }
                printf("%d elements and force %d\n",Red.record[n].nowlife,Red.record[n].attack);
            }
            else if(strcmp(tmp,"ninja")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            else if(strcmp(tmp,"wolf")==0)
                printf("%d elements and force %d\n",Red.record[city[i].RedNum].nowlife,Red.record[city[i].RedNum].attack);
            }
            if(city[i].BlueNum!=0&&Blue.record[city[i].BlueNum].nowlife>0){         
                printf("%03d:%02d blue %s %d marched to city %d with ",hour,minute,
                        Blue.record[city[i].BlueNum].Variety,city[i].BlueNum,i);
                strcpy(tmp,Blue.record[city[i].BlueNum].Variety);
                if(strcmp(tmp,"dragon")==0)
                    printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
                else if(strcmp(tmp,"lion")==0)
                    printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
                else if(strcmp(tmp,"iceman")==0){               
                    if(Blue.record[m].nowlife>9&&(Blue.record[m].step)%2==0){
                        Blue.record[m].nowlife-=9;                  
                        Blue.record[m].attack+=20;
                    }
                    else if((Blue.record[m].nowlife)<=9&&(Blue.record[m].step)%2==0){
                        Blue.record[m].nowlife=1;
                        Blue.record[m].attack+=20;
                    }
                    printf("%d elements and force %d\n",Blue.record[m].nowlife,Blue.record[m].attack);
                }
                else if(strcmp(tmp,"ninja")==0)
                    printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
                else if(strcmp(tmp,"wolf")==0)
                    printf("%d elements and force %d\n",Blue.record[city[i].BlueNum].nowlife,Blue.record[city[i].BlueNum].attack);
            }
        }
    }
    return 0;
}
int produce(){
    for(int i=1;i<=nCity;i++){
        city[i].life+=10;
    }
    return 0;
} 
int acquire(redheadquarter& Red, blueheadquarter& Blue){
    int n,m;
    for(int i=1;i<=nCity;i++){
        n=city[i].RedNum; m=city[i].BlueNum;
        if(n!=0&&Red.record[n].nowlife<=0){city[i].RedNum=0; n=0; }
        if(m!=0&&Blue.record[m].nowlife<=0){city[i].BlueNum=0; m=0; }
        if(city[i].RedNum!=0&&city[i].BlueNum!=0)
            continue;
        if(city[i].RedNum!=0){
            printf("%03d:%02d red %s %d earned %d elements for his headquarter\n",
                hour,minute,Red.record[n].Variety,city[i].RedNum,city[i].life);
            Red.totallife+=city[i].life;        
            city[i].life=0;
        }
        else if(city[i].BlueNum!=0){
            printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                hour,minute,Blue.record[m].Variety,city[i].BlueNum,city[i].life);
            Blue.totallife+=city[i].life;
            city[i].life=0;
        }
    }
    return 0;
}
int redheadquarter::WarriorArrow(blueheadquarter& Blue){
    int m,n; 
    for(int i=1;i<nCity;i++){
        n=city[i].RedNum; m=city[i+1].BlueNum;
        record[n].shot=false; city[i].redshot=false;
        if(n!=0&&m!=0&&record[n].arrow>0){
            record[n].arrow--;
            record[n].shot=true;
            city[i].redshot=true;
            Blue.record[m].nowlife-=record[n].ArrowPower;
        }
    }
    return 0;
}
int blueheadquarter::WarriorArrow(redheadquarter& Red){
    int m,n;
    for(int i=nCity;i>1;i--){
        n=city[i].BlueNum; m=city[i-1].RedNum;

        record[n].shot=false; city[i].blueshot=false;
        if(n!=0&&m!=0&&record[n].arrow>0){
            record[n].arrow--;
            city[i].blueshot=true;
            record[n].shot=true;
            Red.record[m].nowlife-=record[n].ArrowPower;
        }
    }
    return 0;
}
int ShowArrow(redheadquarter& Red,blueheadquarter& Blue){
    int n,m;
    for(int i=1;i<nCity+1;i++){     
        if(city[i].redshot==true){
            city[i].redshot=false;
            n=city[i].RedNum; m=city[i+1].BlueNum;
            printf("%03d:%02d red %s %d shot",hour,minute,Red.record[n].Variety,city[i].RedNum);
            if(Blue.record[m].nowlife<=0&&Blue.record[m].Alive==true){          
                printf(" and killed blue %s %d",Blue.record[m].Variety,city[i+1].BlueNum);
            }
            printf("\n");
        }
        if(city[i].blueshot==true&&i-1>=0){
            city[i].blueshot=false;
            m=city[i].BlueNum; n=city[i-1].RedNum;
            printf("%03d:%02d blue %s %d shot",hour,minute,Blue.record[m].Variety,city[i].BlueNum);
            if(Red.record[n].nowlife<=0&&Red.record[n].Alive==true){            
                printf(" and killed red %s %d",Red.record[n].Variety,city[i-1].RedNum);
            }
            printf("\n");
        }
    }
    return 0;
}
int redheadquarter::BombDeath(blueheadquarter& Blue){
    int tmpn,tmpm;
    bool ifbomb;
    bool redkilled,bluekilled; 
    for(int i=1;i<=nCity;i++){
        tmpn=city[i].RedNum; tmpm=city[i].BlueNum;
        redkilled=false; bluekilled=false;
        if(( (Blue.record[tmpm].attack+(Blue.record[tmpm].sword)*(Blue.record[tmpm].SwordPower)>=record[tmpn].nowlife)
            && ( (city[i].HaveFlag==false&&i%2==0)||(city[i].HaveFlag==true&&strcmp(city[i].flag,"blue")==0) ))
            || ( (Blue.record[tmpm].nowlife>record[tmpn].attack+(record[tmpn].sword)*(record[tmpn].SwordPower) )
            &&  (strcmp(Blue.record[tmpm].Variety,"ninja")!=0)
            && (record[tmpn].nowlife<=Blue.record[tmpm].attack/2+(Blue.record[tmpm].sword)*(Blue.record[tmpm].SwordPower) )
            &&( (city[i].HaveFlag==false&&i%2==1)||(city[i].HaveFlag==true&&strcmp(city[i].flag,"red")==0) ) )){            
                redkilled=true;
            }
        if(((record[tmpn].attack+(record[tmpn].sword)*(record[tmpn].SwordPower)>=Blue.record[tmpm].nowlife)
            && ((city[i].HaveFlag==false&&i%2==1)||(city[i].HaveFlag==true&&strcmp(city[i].flag,"red")==0)))
            || (record[tmpn].nowlife>Blue.record[tmpm].attack+(Blue.record[tmpm].sword)*(Blue.record[tmpm].SwordPower))
            && (strcmp(record[tmpn].Variety,"ninja")!=0)
            && ((Blue.record[tmpm].nowlife<=record[tmpn].attack/2+(record[tmpn].sword)*(record[tmpn].SwordPower))
            &&((city[i].HaveFlag==false&&i%2==0)||(city[i].HaveFlag==true&&strcmp(city[i].flag,"blue")==0))))
                bluekilled=true;
        ifbomb=false;
        if(city[i].RedNum!=0&&record[tmpn].nowlife>0&&city[i].BlueNum!=0&&Blue.record[tmpm].nowlife>0
            &&record[tmpn].bomb==true&&redkilled==true){
            ifbomb=true;
            printf("%03d:%02d red %s %d used a bomb and killed blue %s %d\n",
            hour,minute,record[tmpn].Variety,tmpn,Blue.record[tmpm].Variety,tmpm);
        }
        if(tmpn!=0&&record[tmpn].nowlife>0&&tmpm!=0&&Blue.record[tmpm].nowlife>0&&Blue.record[tmpm].bomb==true&&bluekilled==true){
            ifbomb=true;
            printf("%03d:%02d blue %s %d used a bomb and killed red %s %d\n",
            hour,minute,Blue.record[tmpm].Variety,tmpm,record[tmpn].Variety,tmpn);
        }
        if(ifbomb==true){
            record[tmpn].Alive=false; record[tmpn].nowlife=-1; record[tmpn].bomb=false;
            Blue.record[tmpm].Alive=false; Blue.record[tmpm].nowlife=-1; Blue.record[tmpm].bomb=false;
            city[i].RedNum=0; city[i].BlueNum=0;
        }
        ifbomb=false;
    }
    return 0;
}
int redheadquarter::ReportLife(){
    printf("%03d:%02d %d elements in red headquarter\n",hour,minute,totallife);
    return 0;
}
int blueheadquarter::ReportLife(){
    printf("%03d:%02d %d elements in blue headquarter\n",hour,minute,totallife);
    return 0;
}
int redheadquarter::ReportWeapon(){
    bool tmp;
    int weaponnum;
    for(int i=WarNum-1;i>=1;i--){
        tmp=false; weaponnum=0;
        if(record[i].Alive==true&&record[i].nowlife>0){
            printf("%03d:%02d red %s %d has ",hour,minute,record[i].Variety,i);
            if(record[i].arrow>0){
                printf("arrow(%d)",record[i].arrow);
                weaponnum++;
            }
            if(record[i].bomb==true){
                if(weaponnum>0)
                    printf(",");
                weaponnum++;
                printf("bomb");
            }
            if(record[i].sword==true&&record[i].SwordPower>0){
                if(weaponnum>0)
                    printf(",");
                weaponnum++;
                printf("sword(%d)",record[i].SwordPower);
            }
            if(weaponnum==0)
                printf("no weapon");        
            printf("\n");           
        }
    }
    return 0;
}
int blueheadquarter::ReportWeapon(){
    bool tmp;
    int weaponnum;
    for(int i=1;i<WarNum;i++){
        tmp=false; weaponnum=0;
        if(record[i].Alive==true&&record[i].nowlife>0){
            printf("%03d:%02d blue %s %d has ",hour,minute,record[i].Variety,i);
            if(record[i].arrow>0){
                printf("arrow(%d)",record[i].arrow);
                weaponnum++;
            }
            if(record[i].bomb==true){
                if(weaponnum>0)
                    printf(",");
                weaponnum++;
                printf("bomb");
            }
            if(record[i].sword==true&&record[i].SwordPower>0){
                if(weaponnum>0)
                    printf(",");
                weaponnum++;
                printf("sword(%d)",record[i].SwordPower);
            }
            if(weaponnum==0)
                printf("no weapon");        
            printf("\n");           
        }
    }
    return 0;
}
int redheadquarter::Fight(blueheadquarter& Blue){
    int redearn=0, blueearn=0;
    int n,m,tmp;
    bool ChangeFlags=false;
    for(int i=1;i<=nCity;i++){
        city[i].ifredwin=false; city[i].ifbluewin=false; 
    }
    for(int i=1;i<=nCity;i++){
        n=city[i].RedNum; m=city[i].BlueNum;
        ChangeFlags=false;
        if(!(n!=0&&m!=0))
            continue;   
        if(record[n].nowlife>0&&Blue.record[m].Alive==true&&Blue.record[m].nowlife<=0){
            Blue.record[m].Alive=false;
            city[i].bluewin=0;
            city[i].ifredwin=true; city[i].ifbluewin=false;
            city[i].redwin++;       
            if(strcmp(record[n].Variety,"wolf")==0){
                if(Blue.record[m].arrow>0&&record[n].arrow==0){
                    record[n].arrow=Blue.record[m].arrow;
                    Blue.record[m].arrow=0;
                    record[n].ArrowPower=Blue.record[m].ArrowPower;
                    Blue.record[m].ArrowPower=0;
                }
                if(Blue.record[m].sword==true&&Blue.record[m].SwordPower>0&&record[n].sword==false){
                    record[n].sword=true;
                    record[n].SwordPower=Blue.record[m].SwordPower;
                    Blue.record[m].sword=false;
                    Blue.record[m].SwordPower=0;
                }
                if(Blue.record[m].bomb==true&&record[n].bomb==false){
                    record[n].bomb=true;
                    Blue.record[m].bomb=false;
                }
            }
            if(strcmp(record[n].Variety,"dragon")==0){
                record[n].spirit+=0.2;
                if(record[n].spirit>=0.8&&((city[i].HaveFlag==false&&i%2==1)||
                (city[i].HaveFlag==true&&strcmp(city[i].flag,"red")==0)))
                    printf("%03d:%02d red dragon %d yelled in city %d\n",hour,minute,n,i);
            }
            if(city[i].life>0){
                redearn+=city[i].life;
                printf("%03d:%02d red %s %d earned %d elements for his headquarter\n",hour,minute,record[n].Variety,n,city[i].life);
                city[i].life=0;
            }       
            if(city[i].redwin>=2&&strcmp(city[i].flag,"red")!=0){
                city[i].HaveFlag=true;
                strcpy(city[i].flag,"red");
                printf("%03d:%02d red flag raised in city %d\n",hour,minute,i);
            }
        }   
        if(Blue.record[m].nowlife>0&&record[n].Alive==true&&record[n].nowlife<=0){
            record[n].Alive=false;
            city[i].redwin=0;
            city[i].ifredwin=false; city[i].ifbluewin=true;
            city[i].bluewin++;      
            if(strcmp(Blue.record[m].Variety,"wolf")==0){
                if(record[n].arrow>0&&Blue.record[m].arrow==0){
                    Blue.record[m].arrow=record[n].arrow;
                    record[n].arrow=0;
                    Blue.record[m].ArrowPower=record[n].ArrowPower;
                    record[n].ArrowPower=0;
                }
                if(record[n].sword==true&&record[n].SwordPower>0&&Blue.record[m].sword==false){
                    Blue.record[m].sword=true;
                    Blue.record[m].SwordPower=record[n].SwordPower;
                    record[n].sword=false;
                    record[n].SwordPower=0;
                }
                if(record[n].bomb==true&&Blue.record[m].bomb==false){
                    Blue.record[m].bomb=true;
                    record[n].bomb=false;
                }
            }
            if(strcmp(Blue.record[m].Variety,"dragon")==0){
                Blue.record[m].spirit+=0.2;
                if(Blue.record[m].spirit>=0.8&&((city[i].HaveFlag==false&&i%2==0)||
                (city[i].HaveFlag==true&&strcmp(city[i].flag,"blue")==0)))
                    printf("%03d:%02d blue dragon %d yelled in city %d\n",hour,minute,m,i);
            }
            if(city[i].life>0){
                blueearn+=city[i].life;
                printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                hour,minute,Blue.record[m].Variety,m,city[i].life);
                city[i].life=0;
            }       
            if(city[i].bluewin>=2&&strcmp(city[i].flag,"blue")!=0){
                city[i].HaveFlag=true;
                strcpy(city[i].flag,"blue");
                printf("%03d:%02d blue flag raised in city %d\n",hour,minute,i);
            }
        }
        if(record[n].nowlife<=0||Blue.record[m].nowlife<=0)
            continue;   
        if((city[i].HaveFlag==false&&i%2==1)||(city[i].HaveFlag==true&&strcmp(city[i].flag,"red")==0)){
            printf("%03d:%02d red %s %d attacked blue %s %d in city %d with %d elements and force %d\n",
                hour,minute,record[n].Variety,n,Blue.record[m].Variety,m,i,record[n].nowlife,record[n].attack);
            int tmp=Blue.record[m].nowlife;
            Blue.record[m].nowlife-=record[n].attack;           
            if(record[n].sword==true&&record[n].SwordPower>0){
                Blue.record[m].nowlife-=record[n].SwordPower;
                record[n].SwordPower=record[n].SwordPower*8/10;
                if(record[n].SwordPower<=0)
                    record[n].sword=false;
            }
            if(Blue.record[m].nowlife>0&&strcmp(record[n].Variety,"lion")==0){
                record[n].loyalty-=record[n].dec;
            }   
            if(Blue.record[m].nowlife>0&&strcmp(record[n].Variety,"dragon")==0){
                record[n].spirit-=0.2;
            }       
            if(Blue.record[m].nowlife<=0){
                printf("%03d:%02d blue %s %d was killed in city %d\n",hour,minute,Blue.record[m].Variety,m,i);          
                Blue.record[m].Alive=false;
                city[i].BlueNum=0;              
                city[i].redwin++;
                city[i].ifredwin=true; city[i].ifbluewin=false;
                city[i].bluewin=0;
                if(strcmp(Blue.record[m].Variety,"lion")==0&&tmp>0){
                    record[n].nowlife+=tmp;             
                    Blue.record[m].nowlife=0; tmp=0;
                }           
                if(strcmp(record[n].Variety,"wolf")==0){
                    if(Blue.record[m].arrow>0&&record[n].arrow<=0){
                        record[n].arrow=Blue.record[m].arrow;
                        Blue.record[m].arrow=0;
                        record[n].ArrowPower=Blue.record[m].ArrowPower;
                        Blue.record[m].ArrowPower=0;
                    }
                    if(Blue.record[m].sword==true&&Blue.record[m].SwordPower>0&&record[n].sword==false){
                        record[n].sword=true;
                        record[n].SwordPower=Blue.record[m].SwordPower;
                        Blue.record[m].sword=false;
                        Blue.record[m].SwordPower=0;
                    }
                    if(Blue.record[m].bomb==true&&record[n].bomb==false){
                        record[n].bomb=true;
                        Blue.record[m].bomb=false;
                    }
                }
                if(strcmp(record[n].Variety,"dragon")==0){
                    record[n].spirit+=0.2;
                    if(record[n].spirit>=0.8&&((city[i].HaveFlag==false&&i%2==1)||
                    (city[i].HaveFlag==true&&strcmp(city[i].flag,"red")==0)))
                        printf("%03d:%02d red dragon %d yelled in city %d\n",hour,minute,n,i);
                }
                if(city[i].life>0){
                    redearn+=city[i].life;
                    printf("%03d:%02d red %s %d earned %d elements for his headquarter\n",
                    hour,minute,record[n].Variety,n,city[i].life);
                    city[i].life=0;
                }       
                if(city[i].redwin>=2&&strcmp(city[i].flag,"red")!=0){
                    city[i].HaveFlag=true;
                    strcpy(city[i].flag,"red");
                    printf("%03d:%02d red flag raised in city %d\n",hour,minute,i);
                }
            }           
            bool Rev=false;
            if(Blue.record[m].nowlife>0&&strcmp(Blue.record[m].Variety,"ninja")!=0){
                Rev=true;
                printf("%03d:%02d blue %s %d fought back against red %s %d in city %d\n",
                    hour,minute,Blue.record[m].Variety,m,record[n].Variety,n,i);
                tmp=record[n].nowlife;
                record[n].nowlife-=Blue.record[m].attack/2;             
                if(Blue.record[m].sword==true&&Blue.record[m].SwordPower>0){
                    record[n].nowlife-=Blue.record[m].SwordPower;
                    Blue.record[m].SwordPower=Blue.record[m].SwordPower*8/10;
                    if(Blue.record[m].SwordPower<=0)
                        Blue.record[m].sword=false;
                }
            }       
            if(record[n].nowlife>0&&Blue.record[m].nowlife>0){
                city[i].ifredwin=false; city[i].ifbluewin=false;
                city[i].redwin=0; city[i].bluewin=0;
            }
            if(record[n].nowlife>0&&strcmp(Blue.record[m].Variety,"lion")==0&&Blue.record[m].nowlife>0)
                Blue.record[m].loyalty-=Blue.record[m].dec;
            if(record[n].nowlife>0&&strcmp(record[n].Variety,"dragon")==0&&record[n].spirit>=0.8&&Blue.record[m].nowlife>0
                &&(Rev==true||(strcmp(Blue.record[m].Variety,"ninja")==0)&&(Blue.record[m].nowlife>0)) )
                printf("%03d:%02d red dragon %d yelled in city %d\n",hour,minute,n,i);
            if(record[n].nowlife>0&&strcmp(Blue.record[m].Variety,"dragon")==0&&Blue.record[m].nowlife>0)
                Blue.record[m].spirit-=0.2; 
            if(record[n].nowlife<=0){
                printf("%03d:%02d red %s %d was killed in city %d\n",hour,minute,record[n].Variety,n,i);
                record[n].Alive=false;
                city[i].RedNum=0;               
                city[i].redwin=0;
                city[i].ifredwin=false; city[i].ifbluewin=true;
                city[i].bluewin++;
                if(strcmp(record[n].Variety,"lion")==0&&tmp>0){
                    Blue.record[m].nowlife+=tmp;
                    record[n].nowlife=0; tmp=0;
                }           
                if(strcmp(Blue.record[m].Variety,"wolf")==0){
                    if(record[n].arrow>0&&Blue.record[m].arrow==0){
                        Blue.record[m].arrow=record[n].arrow;
                        record[n].arrow=0;
                        Blue.record[m].ArrowPower=record[n].ArrowPower;
                        record[n].ArrowPower=0;
                    }
                    if(record[n].sword==true&&record[n].SwordPower>0&&Blue.record[m].sword==false){
                        Blue.record[m].sword=true;
                        Blue.record[m].SwordPower=record[n].SwordPower;
                        record[n].sword=false;
                        record[n].SwordPower=0;
                    }
                    if(record[n].bomb==true&&Blue.record[m].bomb==false){
                        Blue.record[m].bomb=true;
                        record[n].bomb=false;
                    }
                }
                if(strcmp(Blue.record[m].Variety,"dragon")==0){
                    Blue.record[m].spirit+=0.2;
                    if(Blue.record[m].spirit>=0.8&&((city[i].HaveFlag==false&&i%2==0)||
                    (city[i].HaveFlag==true&&strcmp(city[i].flag,"blue")==0)))
                        printf("%03d:%02d blue dragon %d yelled in city %d\n",hour,minute,m,i);
                }
                if(city[i].life>0){
                    blueearn+=city[i].life;
                    printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                    hour,minute,Blue.record[m].Variety,m,city[i].life);
                    city[i].life=0;
                }       
                if(city[i].bluewin>=2&&strcmp(city[i].flag,"blue")!=0){
                    city[i].HaveFlag=true;
                    ChangeFlags=true;
                    strcpy(city[i].flag,"blue");
                    printf("%03d:%02d blue flag raised in city %d\n",hour,minute,i);
                }
            }       
        }       
        if((city[i].HaveFlag==false&&i%2==0)||(city[i].HaveFlag==true&&strcmp(city[i].flag,"blue")==0&&ChangeFlags==false)){
            printf("%03d:%02d blue %s %d attacked red %s %d in city %d with %d elements and force %d\n",
                hour,minute,Blue.record[m].Variety,m,record[n].Variety,n,i,Blue.record[m].nowlife,Blue.record[m].attack);
            tmp=record[n].nowlife;      
            record[n].nowlife-=Blue.record[m].attack;           
            if(Blue.record[m].sword==true&&Blue.record[m].SwordPower>0){
                record[n].nowlife-=Blue.record[m].SwordPower;               
                Blue.record[m].SwordPower=Blue.record[m].SwordPower*8/10;               
                if(Blue.record[m].SwordPower<=0)
                    Blue.record[m].sword=false;
            }   
            if(record[n].nowlife>0&&strcmp(Blue.record[m].Variety,"lion")==0){
                Blue.record[m].loyalty-=Blue.record[m].dec;
            }
            if(record[n].nowlife>0&&strcmp(Blue.record[m].Variety,"dragon")==0)
                Blue.record[m].spirit-=0.2;             
            if(record[n].nowlife<=0){
                printf("%03d:%02d red %s %d was killed in city %d\n",hour,minute,record[n].Variety,n,i);                
                record[n].Alive=false;
                city[i].RedNum=0;               
                city[i].bluewin++; city[i].redwin=0;
                city[i].ifredwin=false; city[i].ifbluewin=true;             
                if(strcmp(record[n].Variety,"lion")==0&&tmp>0){
                    Blue.record[m].nowlife+=tmp;
                    record[n].nowlife=0; tmp=0;
                }           
                if(strcmp(Blue.record[m].Variety,"wolf")==0){
                    if(record[n].arrow>0&&Blue.record[m].arrow==0){
                        Blue.record[m].arrow=record[n].arrow;
                        record[n].arrow=0;
                        Blue.record[m].ArrowPower=record[n].ArrowPower;
                        record[n].ArrowPower=0;
                    }
                    if(record[n].sword==true&&record[n].SwordPower>0&&Blue.record[m].sword==false){
                        Blue.record[m].sword=true;
                        Blue.record[m].SwordPower=record[n].SwordPower;
                        record[n].sword=false;
                        record[n].SwordPower=0;
                    }
                    if(record[n].bomb==true&&Blue.record[m].bomb==false){
                        Blue.record[m].bomb=true;
                        record[n].bomb=false;
                    }
                }
                if(strcmp(Blue.record[m].Variety,"dragon")==0){
                    Blue.record[m].spirit+=0.2;
                    if(Blue.record[m].spirit>=0.8&&((city[i].HaveFlag==false&&i%2==0)||
                    (city[i].HaveFlag==true&&strcmp(city[i].flag,"blue")==0)))
                        printf("%03d:%02d blue dragon %d yelled in city %d\n",hour,minute,m,i);
                }
                if(city[i].life>0){
                    blueearn+=city[i].life;
                    printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                    hour,minute,Blue.record[m].Variety,m,city[i].life);
                    city[i].life=0;
                }       
                if(city[i].bluewin>=2&&strcmp(city[i].flag,"blue")!=0){
                    city[i].HaveFlag=true;
                    strcpy(city[i].flag,"blue");
                    printf("%03d:%02d blue flag raised in city %d\n",hour,minute,i);
                }
            }       
            bool Rev=false;
            if(record[n].nowlife>0&&strcmp(record[n].Variety,"ninja")!=0&&Blue.record[m].nowlife>0){
                Rev=true;
                printf("%03d:%02d red %s %d fought back against blue %s %d in city %d\n",
                    hour,minute,record[n].Variety,n,Blue.record[m].Variety,m,i);
                tmp=Blue.record[m].nowlife;
                Blue.record[m].nowlife-=record[n].attack/2;             
                if(record[n].sword==true&&record[n].SwordPower>0){
                    Blue.record[m].nowlife-=record[n].SwordPower;
                    record[n].SwordPower=record[n].SwordPower*8/10;
                    if(record[n].SwordPower<=0)
                        record[n].sword=false;
                }
            }
            if(Blue.record[m].nowlife>0&&strcmp(record[n].Variety,"lion")==0&&record[n].nowlife>0){
                record[n].loyalty-=record[n].dec;
            }
            if(Blue.record[m].nowlife>0&&strcmp(Blue.record[m].Variety,"dragon")==0&&Blue.record[m].spirit>=0.8
            &&(Rev==true||(strcmp(record[n].Variety,"ninja")==0)&&(record[n].nowlife>0)) ){
                printf("%03d:%02d blue dragon %d yelled in city %d\n",hour,minute,m,i);             
            }
            if(Blue.record[m].nowlife>0&&strcmp(record[n].Variety,"dragon")==0&&record[n].nowlife>0)
                record[n].spirit-=0.2;
            if(record[n].nowlife>0&&Blue.record[m].nowlife>0){
                city[i].ifredwin=false; city[i].ifbluewin=false;
                city[i].redwin=0; city[i].bluewin=0;
            }       
            if(Blue.record[m].nowlife<=0){
                printf("%03d:%02d blue %s %d was killed in city %d\n",hour,minute,Blue.record[m].Variety,m,i);
                Blue.record[m].Alive=false;
                city[i].BlueNum=0;              
                city[i].bluewin=0;
                city[i].ifredwin=true; city[i].ifbluewin=false;
                city[i].redwin++;
                if(strcmp(Blue.record[m].Variety,"lion")==0&&tmp>0){
                    record[n].nowlife+=tmp;
                    Blue.record[m].nowlife=0; tmp=0;
                }           
                if(strcmp(record[n].Variety,"wolf")==0){
                    if(Blue.record[m].arrow>0&&record[n].arrow==0){
                        record[n].arrow=Blue.record[m].arrow;
                        Blue.record[m].arrow=0;
                        record[n].ArrowPower=Blue.record[m].ArrowPower;
                        Blue.record[m].ArrowPower=0;
                    }
                    if(Blue.record[m].sword==true&&Blue.record[m].SwordPower>0&&record[n].sword==false){
                        record[n].sword=true;
                        record[n].SwordPower=Blue.record[m].SwordPower;
                        Blue.record[m].sword=false;
                        Blue.record[m].SwordPower=0;
                    }
                    if(Blue.record[m].bomb==true&&record[n].bomb==false){
                        record[n].bomb=true;
                        Blue.record[m].bomb=false;
                    }
                }
                if(strcmp(record[n].Variety,"dragon")==0){
                    record[n].spirit+=0.2;
                    if(record[n].spirit>=0.8&&((city[i].HaveFlag==false&&i%2==1)||
                    (city[i].HaveFlag==true&&strcmp(city[i].flag,"red")==0)))
                        printf("%03d:%02d red dragon %d yelled in city %d\n",hour,minute,n,i);
                }
                if(city[i].life>0){
                    redearn+=city[i].life;
                    printf("%03d:%02d red %s %d earned %d elements for his headquarter\n",
                    hour,minute,record[n].Variety,n,city[i].life);
                    city[i].life=0;
                }       
                if(city[i].redwin>=2&&strcmp(city[i].flag,"red")!=0){
                    city[i].HaveFlag=true;
                    strcpy(city[i].flag,"red");
                    printf("%03d:%02d red flag raised in city %d\n",hour,minute,i);
                }
            }
        }    
    }   
    for(int i=nCity;i>=1;i--){
        if(totallife<8)
            break;
        if(record[city[i].RedNum].nowlife<=0){
            record[city[i].RedNum].Alive=false;
        }
        if(city[i].ifredwin==true&&record[city[i].RedNum].nowlife>0){
            record[city[i].RedNum].nowlife+=8;
            totallife-=8;
        }
    } 
    for(int i=1;i<=nCity;i++){
        if(Blue.totallife<8)
            break;
        if(Blue.record[city[i].BlueNum].nowlife<=0)
            Blue.record[city[i].BlueNum].Alive=false;
        if(city[i].ifbluewin==true&&Blue.record[city[i].BlueNum].nowlife>0){
            Blue.record[city[i].BlueNum].nowlife+=8;
            Blue.totallife-=8;
        }
    }
    totallife+=redearn;
    Blue.totallife+=blueearn;
    return 0;
} 
