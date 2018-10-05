# PyCharm & Tensorflow?
## macOS에 아나콘다를 이용해 python3.6 버전을 설치하고 tensorflow를 돌릴 수 있는 환경 설치
1. [아나콘다 설치](https://www.continuum.io/downloads#macos)
* python은 3.x 버전 이상으로 설치
* 콘다 버전확인: ```$ conda --version```
* 파이선 버전확인: ```$ python -V```
---
2. 콘다 환경 생성
* 파이선 환경에 맞게 설정(나의 경우 3.6)
```$ conda create -n tensorflow python=3.6```
* conda 환경 활성화: ``` $ source activate tensorflow ```
---
3. pip3를 이용하여 tensorflow 설치(복잡주의)
* pip version 확인: ```$ pip3 -V ```
* ``` (tensorflow)$ sudo easy_install --upgrade pip ```
* ``` (tensorflow)$ sudo easy_install --upgrade six ```
* ``` (tensorflow)$ pip3 install tensorflow ```
* 설치완료
---
4. PyCharm interpreter 경로 설정 
* [파이참 설치](https://www.jetbrains.com/pycharm/download/#section=mac)
<i>학생계정으로 무료사용 가능</i>
* interpreter 경로로 네이밍 한 conda 환경 이름(tensorflow)내의 python 파일로 설정
---
