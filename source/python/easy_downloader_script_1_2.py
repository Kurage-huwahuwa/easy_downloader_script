import subprocess
import os

def down():

    print("┌-------------------------------┐")
    print("￤色んな動画をダウンロードします￤")
    print("└-------------------------------┘")
    down_link = input("ダウンロードリンク:")

    if "https://abema.tv/video/" in down_link:
        i = 0
        down_file = input("保存名:")
    elif "https://www.nicovideo.jp/" in down_link:
        i = 1
    elif "https://www.youtube.com/" in down_link:
        i = 1
    elif "https://gyao.yahoo.co.jp/" in down_link:
        i = 1
    elif "https://jp.pornhub.com/" in down_link:
        i = 1
    elif "https://youtu.be/" in down_link:
        i = 1
    else :
        while True:
                print("リンクが正しくありません")
                down_link = input("リンクを入力してください:")
                if "https://abema.tv/video/" in down_link:
                    i = 0
                    down_file = input("保存名:")
                    break
                elif "https://www.nicovideo.jp/" in down_link:
                    i = 1
                    break
                elif "https://www.youtube.com/" in down_link:
                    i = 1
                    break
                elif "https://gyao.yahoo.co.jp/" in down_link:
                    i = 1
                    break
                elif "https://jp.pornhub.com/" in down_link:
                    i = 1
                elif "https://youtu.be/" in down_link:
                    i = 1
                    break

    karento = os.path.join(os.path.expanduser('~'),"Videos")
    os.chdir(karento)

    if i == 0:
        if not ".mp4" in down_file:
            down_file = down_file+".mp4"

        print("ダウンロードを開始します")

        subprocess.run(["streamlink",down_link,"best","-o",down_file])

    elif i == 1:
        if  "mp3" in down_link:
            print("mp3形式でダウンロードします")
            cmd = "yt-dlp -f \"bestaudio/best\" -ciw -o \"%(title)s.%(ext)s%\" -v --extract-audio --audio-quality 0 --audio-format "+down_link
            subprocess.run(cmd)
            return

        print("ダウンロードを開始します")
        cmd = "yt-dlp -f \"bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best5\" "+down_link
        subprocess.run(cmd)
        print("ダウンロードが終了しました")

    if i == 2:
        print("エラー")

down()

while True:
    print("続行しますか")
    ans = input("y or n:")
    if ans == "y" or ans == "Y":
        down()
    elif ans == "n" or ans == "N":
        print("終了します")
        break