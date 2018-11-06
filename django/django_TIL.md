## Django

### 웹 서버 실행
- `cd ~` 로 최상위 폴더로 이동
1. `python manage.py migrate` 
2. `python manage.py runserver` 하면 server 실행 


### 새 앱 생성 후
1. `~/djangogirls$ python manage.py startapp myapp`
2. `myapp` 의 하위 폴더의 `models.py` 를 원하는 모델로 수정
3. `mysite/settings.py` 를 통해 새 어플리케이션을 생성했다고 장고에게 알려줌
4. `INSTALLED_APPS` 를 열어 마지막 줄에 `myapp`을 추가해 주면 된다.

### 실행하기
1. `~/djangogirls$ python manage.py makemigrations myapp`
2. `~/djangogirls$ python manage.py migrate myapp`