#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdint.h>
#define N "N"
#define NN "n"
#define Y "Y"
#define YY "y"
#define LEN 1000
#define ABEMA "https://abema.tv/video/"
#define KAKU ".mp4"

void abema(void);
void lntrim(char *str);

int main(){
    char ans[100];
    int i;

    abema();

    for(;;){
        printf("続行しますか[Y/N]:");
        scanf("%s",ans);

        if((strcmp(ans,Y)&&(strcmp(ans,YY))) == 0){
            printf("続行します\n");
            abema();
        }else if((strcmp(ans,NN)&&(strcmp(ans,N))) ==0){
            printf("終了します\n");
            break;
        }else{
            printf("入力された値は無効です（値:%s）\n",ans);
        }   
    }    
    return 0;
}

void abema(void){

    char rinku[100],file[1000],cd[100],comando[10000],comando2[1000];

    printf("┌-------------------------------┐\n");
    printf("￤abema動画をダウンロードします ￤\n");
    printf("└-------------------------------┘\n");
    printf("リンクを入力してください:");
    fgets(rinku, sizeof(rinku), stdin);
    //改行を消す
    void lntrim(char *rinku);
    lntrim(rinku);
    

    if(strncmp(rinku,ABEMA,23)==0){
    }else{
        printf("エラー\n");
        for(;;){
            printf("正しいリンクを入力してください:");
            fgets(rinku, sizeof(rinku), stdin);
            if(strncmp(rinku,ABEMA,22)==0){
                void lntrim(char *rinku);
                lntrim(rinku);
                break;
            }
        }
    }
    
    printf("\n保存名を入力してください:");
    fgets(file, sizeof(file), stdin);
    //改行を消す
    void lntrim(char *file);
    lntrim(file);

    if (strstr(file,KAKU)!=0){
    }else{
        sprintf(file,"%s%s",file,KAKU);
        printf("%s",file);
    }

    sprintf(comando,"streamlink %s best -o %s",rinku,file);
    system(comando);
}

void lntrim(char *str){

  char *p;

  p = strchr(str,'\n');
  if(p != NULL){
    *p = '\0';
  }
}
