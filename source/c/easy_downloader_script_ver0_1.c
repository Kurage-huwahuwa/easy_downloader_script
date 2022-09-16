#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define N "N"
#define NN "n"
#define Y "Y"
#define YY "y"


void abema(void);

int main(){


    char ans[100];
    int i;
    abema();

    while(i < 3){
        printf("終了しますか[Y/N]:");
        scanf("%s",ans);

        if((strcmp(ans,Y)&&(strcmp(ans,YY))) == 0){
            i = 0;

        }else if((strcmp(ans,NN)&&(strcmp(ans,N))) ==0){
            i = 4;
        }else{
            i = 2;
        }

    switch (i){
        case 0:
            printf("続行します\n");
            abema();
            break;

        case 4:
            printf("終了します\n");
            break;

        default:
            printf("入力された値は無効です（値:%s）\n",ans);
            break;
    }
    

    }    
    return 0;

}

void abema(void){

    char rinku[100],file[100],cd[100],comando[1000],comando2[1000];

    printf("┌-------------------------------┐\n");
    printf("￤色んな動画をダウンロードします ￤\n");
    printf("└-------------------------------┘\n");
    printf("リンクを入力してください:");
    scanf("%s",rinku);
    printf("\n保存名を入力してください:");
    scanf("%s\n",file);
    scanf("%s",file);
    sprintf(comando,"streamlink %s best -o %s\n",rinku,file);
    system(comando);
    sprintf(comando2,"ffmpeg -i %s -c copy %s.mp4",file,file);
    system(comando2);

}
