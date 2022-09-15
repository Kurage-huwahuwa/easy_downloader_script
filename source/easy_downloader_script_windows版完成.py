import subprocess
import os

def down():
    print("┌-------------------------------┐")
    print("￤abema動画をダウンロードします￤")
    print("└-------------------------------┘")
    down_link = input("abemaのダウンロードリンク:")
    down_file = input("保存名:")
    karento = os.path.join(os.path.expanduser('~'),"Videos")
    os.chdir(karento)

    """
    #拡張子削除
    henkan = os.path.basename(down_file)
    down_file = os.path.splitext(henkan)[0]
    """
    subprocess.run(["streamlink",down_link,"best","-o",down_file])
    #上手く動画が再生されなかった場合に↓
    #subprocess.run(["ffmpeg","-i",down_file,"-c:v","copy","-c:a","copy",down_file+".mp4"])
    #os.remove(down_file)


down()

while True:
    print("続行しますか")
    ans = input("y or n:")
    if ans == "y" or ans == "Y":
        down()
    elif ans == "n" or ans == "N":
        print("終了します")
        break
