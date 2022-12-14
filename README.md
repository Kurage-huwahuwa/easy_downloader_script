スクリプトファイル
=================
このスクリプトはyoutubeなどの動画をダウンロードしてくれる「yt-dlp」、「streamlink」を簡単に使いやすくするものです。

  
動作環境
--------
python3が必要です<br>
➀windows→ https://pythonlinks.python.jp/ja/index.html<br>
　Ubuntu系→ sudo apt install python3-pip<br>
➁コマンドプロント等で下のコマンドを実行<br>
　`$ pip3 install streamlink`<br>
　`$ pip3 install  yt-dlp`<br>

OSに関してはほとんどの環境で動作するはずですが一応

  windows 7 starter<br>
  Xubuntu 20.04<br>
  windows 11 
  
これらの環境では動作確認済みです

使い方
-----
➀ダウンロードしたい動画サイトの動画のサムネイルを右クリック、アドレスバーのリンクをコピー

➁「ダウンロードリンク :」でリンクを貼り付け<br>
abemaのリンク以外であれば、リンクの前に空白をつけて"mp3"を入力するとmp3形式で取り込みます<br>
例）<br>
`mp3 https://www.youtube.com/hoge`<br>

➂（abemaのリンクのみ）「保存名 :」で保存名を決定<br>
もしファイルパスをパスを入力すればそこにダウンロードしてくれます<br>
例）<br>
`C:\Users\user_name\Downloads\hogehoge.mp4`<br>
`/home/user_name/デスクトップ/hogehoge`<br>
（拡張子はこのスクリプト側で判断するのでなくてもokです）<br>

➃（保存先を指定しなかった場合、）windowsならVideo、linuxならビデオフォルダーにダウンロードされます<br>

ダウンロードされる画質、音質
-----------------------
最高画質、音質となっています。<br>


対応サイト
----------
Abema<br>
niconico<br>
YouTube<br>
GYAO<br>
Pornhub（←念のために対応させました。）<br>

※yt-dlpとstreamlinkの対応サイトが多すぎてキリがないので主要サイトと思われるもののみ抑えています

ソースコード
-----------
なんとなくpython、c言語で記述したファイルを用意しました。<br>
※どちらもwindows、linuxで不具合なくプログラムが完走する（はずです）。<br>
※処理している事自体はほとんど同じです。<br>
※プログラミング超絶スーパーウルトラ初心者なのでコードが汚いです。ご了承ください。<br>
※unix系は何も試してません<br>
そのため、ダウンロードしたいサイト等があれば適宜コードに追加してください。<br>

↓から対応サイトを確認できます。<br>
streamlink → https://streamlink.github.io/<br>
yt-dlp→ https://github.com/yt-dlp/yt-dlp/blob/master/supportedsites.md<br>
