# xy-axis-robo-BluePill
STM32F103(BluePill)用の、、STM32CubeIDEのワークスペース。
回路図は以下の通り。
![circuit-board](xy-axis-robo-controll-board.png)
[ロボのグリッパー部のリポジトリ](https://github.com/Naoto8734/gripper-robo-BluePill)

## 書き込み方法
OSはUbuntu。[J-Link EDU](https://www.embitek.co.jp/product/jlink-edu.html)を使用し、STM32CubeIDEで生成したbinファイルを書き込み。
**BluePill側の電源(3.3v)を入れておくこと。**
参考：[J-LinkでコマンドラインからマイコンのFlashに書き込む](http://idken.net/posts/2019-07-14-jlinkflash/)

### BluePillとJ-Link EDUとのピン接続

| SWD(JLink) | Pin# | | BluePill |
 ---- | ---- | ---- | ---- | ---- 
| VTref | 1 | |3V3(SWD-Connector) |
| GND | 4 | | GND(SWD-Connector) |
| SWDIO | 7 | | DIO(SWD-Connector) |
| SWCLK | 9 | | DCLK(SWD-Connector) |
| RESET | 15 | | R |