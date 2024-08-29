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

---

<img src = image/image01.png>

### 테트리스 START PART
- Reset Parameter Value
- 게임요소 관련 변수 & key, SW, 7-seg값 초기화

#### Set Timer
- Timer interval 10ms로 설정, 필요 register 활성화
- Set interrupt register enable
- Dual Buffering for V-SYNC
- Start Wait roof
- Button Interrupt 에 따라 Status인 RUN 값이 바뀌며 이에 따라 while roof를 빠져 나오며 실제 테트리스 메인 루프로 이동

---

<img src = image/image02.png>

### 테트리스 MAIN PART
- Reset Block Map Parameter
Ex) 블록 위치, 회전 상태, 종류 변수

#### Block Control
- 블록 맵을 참조하여 블록 컨트롤 변수 설정

#### Add to Nums, Blockmap
- 블록이 틀이나 블록을 뚫으며 비정상적 동작하지 않도록 통제

#### Block control
- 입력받은 변수와 Timer Interval을 사용, 1초 간격으로 이동하도록 한다.
- 비정상적 동작 경우 이동, 회전 취소

#### Block Stack
- 블록이 쌓인 경우 Nums 갱신

#### Line Remove
- 한 줄에 block이 모두 쌓인 경우 제거

---

<img src = image/image03.png>

### 테트리스 END PART

#### PLAY GAME DISPLAY : 
- 컨트롤 블록을 반영한 출력 블록 맵에 블록 생성, 플레이어 점수를 기록.플레이어 전환하여 게임진행. 

#### GAME END DISPLAY : 
- 만약 플레이어 2에서 전환되어야하는 경우, 플레이어1 과 플레이어2의 점수를 비교하여 점수가 높은 플레이어를 WIN으로 출력. 
- 루프를 돌며 계속 Dual Buffering 출력하며 종료.(비긴 경우, DRAW출력)

---

# :pencil:4. Design Technic

<img src = image/image05.png>

# :pencil:6. Project Assesment

<img src = image/image06.png>

<img src = image/image07.png>

# Contact
- 📧 wodud6423@kau.kr

