#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#define N "N"
#define NN "n"
#define Y "Y"
#define YY "y"
#define LEN 1000
#define ABEMA "https://abema.tv/video/"
#define KAKU ".mp4"
#define PATH_SIZE 512
#define BUF 256

void windows_karento(void);
void abema(void);
void lntrim(char *str);
void karento(void);

int main(){
    char ans[100];
    int i;


    karento();
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

/*abemaの動画をダウンロード*/
void abema(void){

    char rinku[100],file[1000],cd[100],comando[10000],comando2[1000];
    char a[]="\"";

    printf("┌-------------------------------┐\n");
    printf("￤abema動画をダウンロードします ￤\n");
    printf("└-------------------------------┘\n");
    printf("リンクを入力してください:");
    fgets(rinku, sizeof(rinku), stdin);

    //改行を消す
    void lntrim(char *rinku);
    lntrim(rinku);

    //リンクの正誤を確認
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

    //拡張子がついていない場合に付与
    if (strstr(file,KAKU)!=0){
    }else{
        sprintf(file,"%s%s",file,KAKU);
    }
    sprintf(comando,"streamlink %s best -o %s%s%s",rinku,a,file,a);

    //streamlink実行
    system(comando);
}

/*fget関数による改行を削除*/
void lntrim(char *str){

  char *p;

  p = strchr(str,'\n');
  if(p != NULL){
    *p = '\0';
  }
}

/*カレントディレクトリ設定*/
void karento(void){

    char home[1000],pwd[100],video[1000],video2[1000];
    struct stat statBuf;

    #if(defined(linux))
    {
        strcpy(home, getenv("HOME"));
        strcpy(pwd, getenv("PWD"));
        chdir(home);
        sprintf(video,"%s/ビデオ",home);
        sprintf(video2,"%s/video",home);
        if (stat(video,&statBuf)==0){
            chdir(video);
            printf("%s\n",video);
        }else if(stat(video2,&statBuf)==0){
            sprintf(video,"%s/video",home);
            chdir(video);

        }else{
            printf("エラー");
        }
    }
    #elif (WINVER >= 0x030a)
    {
        windows_karento();
    }
    #else
    {
        printf("error\n");
        printf("linux、windows以外のOSが検出されました")
    }
    #endif
}

/*windows内のビデオフォルダーを指定*/
void windows_karento(void){ 
    FILE *fp;
    char home[100];
    char buf[BUF];
    char shell[100]="echo %USERNAME%";


    fp = popen(shell, "r");
    while(fgets(buf, BUF, fp) != NULL){
        fputs(buf, stdout);
    }
    pclose(fp);

    void lntrim(char *buf);
    lntrim(buf);
    sprintf(home,"c:\\Users\\%s\\Videos",buf);
    chdir(home);
}
