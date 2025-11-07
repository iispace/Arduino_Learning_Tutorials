# Fritzing part 만들기

- fritzing part를 만들기 위해서는 아래와 같이 4가지 종류의 svg 파일을 하나씩 만들어야 하는데, 빈 파일에서 모든 svg 파일을 그리는 것은 비효율적이므로, 기존의 parts 중에서 최대한 비슷한 것을 찾은 후, 해당 part의 svg 파일들을 불러서 필요한 곳만 편집/수정하는 방법으로 진행한다.

  - breadboard
  - icon
  - pcb
  - schematic

- 여기서는 svg 파일의 편집을 위한 프로그램으로 inkscape를 사용한다. 

### 1. Fritzing에서 만들고자하는 part와 가장 유사한 모양을 하고 있는 기존 부품 선택 

  <img width="721" height="463" alt="image" src="https://github.com/user-attachments/assets/d6066e65-7a31-499a-8b99-20b2d0aac3db" />


### 2. svg 파일 만들기

  - 파일 탐색기를 통해 "사용자계정\AppData\Local\Programs\Fritzing\fritzing-parts\svg\core" 에 가 보면 아래와 같이 4개의 하위 폴더가 있다.

    <img width="770" height="362" alt="image" src="https://github.com/user-attachments/assets/df9edecb-e63b-4129-8eea-0a9fa89ff6b7" />


  - 위 그림에 있는 4개의 폴더들을 차례로 들어가서 fritzing에서 선택한 기존 부품의 svg 파일을 찾아 나의 작업 경로에 복사해 온다. 서로 다른 이미지라 하더라도 각 폴더별로 파일의 이름이 같을 수 있으므로, 나의 작업 경로에도 4개의 하위 폴더를 만들어 놓고, 각 하위 폴더별로 svg 파일을 저장한다.

  - 4개의 폴더별로, 복사해 온 svg 파일을 inkscape로 열고 하나씩 필요한 대로 편집한 후  "다른 이름으로 저장"하기를 선택하여 적절한 이름으로 저장한다.

  - 아래 화면은 "fc-51_2.svg" 파일을 복사해 온 상황에서 inkscape로 해당 파일을 연 모습이다.

    <img width="890" height="500" alt="image" src="https://github.com/user-attachments/assets/632e5e67-7c38-4ccb-9975-6138dfba26d2" />

    - 참고로, fritzing에서 지원하는 폰트는 OCRA이므로, 현재 본인의 컴퓨터에 OCRA 폰트가 설치되어  있어야 한다. 해당 폰트를 설치한 후, inkscape를 종료 후 다시 시작하면 폰트 목록에 OCRA 폰트가 보인다.
   

  - 이제 inkscape에서 편집 작업을 시작한다.

    - 전체 이미지를 선택한 후, 아래 그림과 같이 마우스 오른쪽 버튼을 클릭해서 "그룹 해제"를 해 주면, 이미지에 보이는 작은 부품들을 하나씩 선택할 수 있게 된다. 이 상태에서 지울 것은 지우고, 위치를 옮길 것은 마우스를 드래그하여 옮길 수 있다.(미세하게 위치 조정을 하고 싶다면, Alt 키를 누른채로 키보드의 화살표를 사용하면 된다).
      
      <img width="296" height="400" alt="image" src="https://github.com/user-attachments/assets/bf0a9184-d7d5-48ca-bc1f-d2f6b814f445" />
      <img width="530" height="400" alt="image" src="https://github.com/user-attachments/assets/efc9ddbc-a88e-4b3f-b0d5-7a1efd93056c" />

   - 단위 부품이라 하더라도, 하나 이상의 이미지가 소그룹으로 묶여 있을 수 있으므로, 단위 부품의 사본을 추가하고자 할 때는 해당 부품을 이루고 있는 소그룹을 모두 선택한 후 복사해야 한다.
   - 예를 들어, OUT 핀을 복사해서 왼쪽 옆에 핀을 하나 더 만들고 싶다면, 아래 그림처럼 해당 부품을 구성하고 있는 요소들을 모두 선택해서 사본을 만들어야 한다.

     <img width="444" height="400" alt="image" src="https://github.com/user-attachments/assets/3a2ff2a0-5aca-47d3-a4c9-138151cc4a6c" />

     - 해당 요소들을 모두 선택한 후 마우스 오른쪽 버튼을 눌러 "사본 만들기"를 해도 되고, 이미지 위에서 해당 핀이 있는 영역을 마우스로 드래그해서 선택한 후 Ctrl+C and Ctrl+V를 해도 된다. 단, "사본 만들기"를 한 경우에는 만들어진 사본이 원본과 동일한 위치에 만들어지므로, 눈으로 보기에는 사본이 어디에 만들어 졌는지 잘 보이지 않을 수 있다(원본과 겹쳐져 있기 때문에...).
       
       <img width="530" height="400" alt="image" src="https://github.com/user-attachments/assets/ca8ce7c4-01be-4b42-8031-0d773d0302ae" />

       - 아래 그림은 마우스를 클릭한 상태에서 OUT 핀 부분이 모두 선택되도록 드래그하는 방법으로 단위 부품을 이루는 모든 요소들을 한꺼번에 선택한 후 Ctrl+C, Ctrl+V를 한 모습이다.
         
         <img width="558" height="400" alt="image" src="https://github.com/user-attachments/assets/2690904c-dfc3-4200-adc7-33ac952bc09c" />

      - 새로 생성된 부품의 이미지를 필요한 곳에 마우스를 드래그하여 위치시킨다.
      - 만일, 연결핀(connection pin)을 새로 만들었다면, id 속성의 값을 fritzing에서 인식할 수 있는 값으로 잘 주어야 한다.

        <img width="734" height="500" alt="image" src="https://github.com/user-attachments/assets/49b45cba-6af4-468f-a9fd-f3dfc99af02b" />

        - connector를 나타내는 요소의 id는 중복이 있어서는 안되며, connector0pin, connector1pin 과 같은 형식으로 준다. 형식이 connector"N"pin 이렇게 되단고 했을 때, "N"에 들어갈 값은 fritzing에서 인식하는 pin의 id번호와 일치해야 한다.
        
        <img width="1166" height="479" alt="image" src="https://github.com/user-attachments/assets/d854b997-0c62-45e4-8599-4b58405ec379" />

         - 위 그림 중 왼쪽은 선택한 기존 부품이 가지고 있는 핀의 개수를 그대로 보여주고 있고, 오른쪽의 것은 연결 핀을 추가해서 총 4개의 핀을 만들 것이므로, number of connections의 값을 4로 수정하고 엔터키를 쳤을 때의 모습니다.
         - 각 핀에 대한 정보가 Name, Description, id 이렇게 보이는데, 가만히 보면 핀의 개수가 3일 때 마지막 핀의 id는 "connector2" 였는데, 4로 바꾸었을 때는 마지막 핀의 id가 "connector4"로 나타난다.
         - 이 경우, inkscape에서 새로 만들어 준 요소의 id값은 connector4pin으로 설정되어야 한다. (id값 설정은 해당 요소를 선택한 후 오른쪽 마우스 버튼 클릭 후, "객체 특성(O)..."를 클릭하면 설정할 수 있는 창이 나온다.
         - connector"N"pin 요소 외에 connector"N"terminal 요소도 같은 요령으로 id 값을 설정한다.
           <img width="468" height="400" alt="image" src="https://github.com/user-attachments/assets/2eaacea0-bd9f-41e0-9498-87f9be29e375" />
           <img width="524" height="400" alt="image" src="https://github.com/user-attachments/assets/f227b323-a9ed-40de-bd07-bf9b270a3a9a" />
           <img width="412" height="1003" alt="image" src="https://github.com/user-attachments/assets/daa348e2-86a8-4890-ae84-17d23bde61c5" />




   - 위와 같은 요령으로 breadboard, icon, pcb, schematic 에 해당하는 svg 파일들을 모두 만들어 주면 inkscape 작업은 끝. 이제 frizting으로 다시 돌아가서 처음에 선택해 둔 기존의 part를 마우스 오른쪽 클릭하고 "Edit(new parts editor)"를 선택한다.

     <img width="620" height="400" alt="image" src="https://github.com/user-attachments/assets/ef0d7cc3-d021-4dea-a945-9f177cdc17cf" />

     - 아래 그림처럼 가장 먼저 "컨넥터"를 선택하여 커넥터의 개수를 맞춰준다.
       
       <img width="464" height="400" alt="image" src="https://github.com/user-attachments/assets/09a48601-427c-4f3f-92e0-b0f5239b16ec" />

     - 두 번째로는 "아이콘"으로 가서 "파일" 매뉴 하위에 있는 "Load image for view..."를 클릭한 후 위에서 만들어 두었던 icon 폴더에 해당하는 svg 파일을 선택해 준다.
       
       <img width="928" height="400" alt="image" src="https://github.com/user-attachments/assets/1a4a6154-ed5b-42b3-85e0-0f73f32818b0" />

      - 세 번째로 "PCB"로 이동해서  "파일" 매뉴 하위에 있는 "Load image for view..."를 클릭한 후 위에서 만들어 두었던 pcb 폴더에 해당하는 svg 파일을 선택해 준다.
        
        <img width="1040" height="400" alt="image" src="https://github.com/user-attachments/assets/9951be75-0e5a-487d-bca6-1b6996b7bbc8" />

      - 네 번째와 다섯 번째로 "스케메틱"과 "브레드보드"로 각각 이동해서 "파일" 매뉴 하위에 있는 "Load image for view..."를 클릭한 후 해당하는 폴더에 만들어 두었던 svg 파일을 선택해서 바꿔주면 수정 작업은 완료.
    
  - 마지막으로, 저장을 반드시 해야 다음에도 사용할 수 있다.
    
      <img width="856" height="400" alt="image" src="https://github.com/user-attachments/assets/e2dc2449-1c6e-4a25-8213-2448284ee739" />





         


