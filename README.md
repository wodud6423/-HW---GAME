# Tetris Game By DE1-SOC Board (ARM Architecture)


<!--프로젝트 대문 이미지-->
<img src = image/Title.gif>

## :dvd:DE1-SOC TETRIS GAME 


# :black_nib:1. Research necessity

<img src = image/Tetrisimage.png>

#### - 저희 조는 항목을 채우기 위하여 Interrupt나 Timer interval을 사용하는 것이 아닌 실질적 동작을 위해 위 기능들을 사용하고 이를 통해 이용 가능한 프로그램을 동작 시키는 것이 가장 중요한 항목이라 생각하며 프로젝트 주제를 선정하였습니다.

#### - 앞선 동기를 충족하기에 테트리스가 좋은 주제라 생각하였으며 Interrupt와 Timer interval 의 활용성과 프로젝트 완성 기간을 고려하여 여러 주제 중 테트리스를 선정하였습니다.

# :checkered_flag:2. Project Goal

#### 테트리스 라는 프로그램을 구성하는 내부 함수들 설계
#### - (ex: 블록 쌓기, 쌓인 줄 제거, 종료 선언, 다음 블록 예고)

#### Timer interval 설정 후 Interrupt를 이용한 게임 속도 조절

#### POLLED IO 방식을 이용한 블록 이동 및 회전 상태 변환

#### Button interrupt를 이용한 게임 실행


# :wrench:3.Project System Design

<img src = image/image01.png>
### 테트리스 START PART
- Reset Parameter Value
- 게임요소 관련 변수 & key, SW, 7-seg값 초기화


### Set Timer
- Timer interval 10ms로 설정, 필요 register 활성화
- Set interrupt register enable
- Dual Buffering for V-SYNC
- Start Wait roof
- Button Interrupt 에 따라 Status인 RUN 값이 바뀌며 이에 따라 while roof를 빠져 나오며 실제 테트리스 메인 루프로 이동




![image](https://github.com/user-attachments/assets/751bb074-7124-460d-a5e6-92d716d557cc)


# 4. Project Process

## 🦮비문 영상 처리부
![Project Title](img/비문영상처리설명01.png)

![Project Title](img/비문영상처리설명02.png)


## 🚪블록 체인 구현부 
![Project Title](img/블록체인구현설명01.png)

![Project Title](img/블록체인구현설명02.png)

![Project Title](img/블록체인구현설명03.png)

![Project Title](img/블록체인구현설명04.png)

![Project Title](img/블록체인블록구조01.png)

(블록체인 블록 구조)


## 📱어플리케이션 구현
![Project Title](img/어플리케이션설명01.png)

![Project Title](img/어플리케이션설명02.png)

![Project Title](img/어플리케이션설명03.png)

![Project Title](img/어플리케이션설명04.png)


# Contact
- 📧 wodud6423@kau.kr

