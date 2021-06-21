+++++ M-HIVE Ground Station V0.9.7 +++++

< How to use >
  - 3DR Telemetry 모듈을 USB에 연결. (CP210x 최신 드라이버 설치 권장)
  - 컴포트 및 통신속도를 알맞게 설정 후 Connect.
  - FC↔GCS 통신 프로토콜 V0.9.1 메시지 프레임에 따라 데이터 송수신.
    (STM32 자작드론 개발하기 강좌 FC↔GCS 통신 프로토콜 v0.9.1.pdf 파일 참조)
  - 반드시 실행파일 폴더에 GMap.NET.Core.dll, GMap.NET.WindowsForms.dll, ZedGraph.dll 세개의 파일이 같이 존재해야함.

  - "STM32CubeIDE를 이용한 STM32F4 자작드론 개발하기" 동영상 강좌에 자세한 사용법이 안내되어있음.
    https://www.inflearn.com/course/STM32CubelDE-STM32F4%EB%93%9C%EB%A1%A0-%EA%B0%9C%EB%B0%9C

1. Comport 설정 및 Terminal 기능
  - 포트 및 통신속도 설정
  - 터미널 Ascii 및 Hex 송수신

2. MAP 기능 (Gmap.net)
  - 현재 좌표 마커 표시
  - 현재 좌표 위도, 경도 표시
  - 이전 30개 좌표 마커 표시
  - 현재 헤딩 표시

3. PID 게인 설정 기능
  - PID 게인 송신
  - PID 게인 요청
  - Send 버튼 누르면 게인 자동 파일 저장 (\Gain Log 폴더)

4. Sensor Graph 시각화 기능 (ZedGraph)
  - 롤/피치/요/고도 그래프
  - 현재상태/제어목표 동시 그래프 출력
  - 센서 로그 파일 저장 기능 (\Sensor Log 폴더)

5. 상태 표시 및 기타 기능
  - GCS ↔ 3DR 모듈 유선 연결 상태 표시
  - GCS ↔ FC 무선 연결 상태 표시 및 통신 두절 알람
  - 배터리 전압 표시 및 저전압 알람
  - FS-i6 SWA, SWC 상태 표시
  - FS-i6 ↔ iA6B Fail-safe 상태 표시 및 알람

  - 프로그램 실행 시, 최근에 송신한 게인 자동 로드 (\Gain Log\Latest.ini 에 저장된 게인 로드)


< List of known issues >
1. 컴포트 Connect한 상태에서 USB 강제로 제거되면 Disconnect 불가능.
  → 프로그램 재실행해야함.

2. 터미널 기능 활성화 시, 전체 프로그램 느려지는 버그.
  → 필요한 경우에만 터미널 기능을 활성화 시키고 그 외엔 터미널 기능 비활성화.

3. 터미널 HEX 송신 시, 앞 뒤에 빈칸이 있으면 에러나는 버그.
  → HEX 송신 시, 앞 뒤 빈칸 제거한 후 송신할 것.

4. 데이터가 너무 빨리 수신되면 그래프가 느려지는 버그.
  → FC에서 최대 50Hz로 메시지 송신 권장.

5. PID 게인 전송 시 가끔 이상한 데이터 수신되는 버그.
  → FC로 게인 요청하여 반드시 현재 FC에 설정된 게인 확인할 것.

Copyright(c) 2020, ChrisP @ M-HIVE

===== M-HIVE Ground Station Update History =====
< V0.9.7 >
  - ZedGraph API 버전 5.1.7로 변경 (이전은 ZedGraph 5.1.5였음) → ZedGraph API 업데이트 내용은 https://www.nuget.org/packages/ZedGraph/ 참조
  - 처음 실행 시, \\Gain Log\Latest.ini 파일의 이전 게인 로드 중, 롤, 피치 게인이 같은 값으로 로드 되는 문제 수정
  - 수신 메세지의 체크섬 계산 시, 바이트 18번의 값을 체크섬 계산에 사용하지 않았던 오류 수정
  + 2020년 3월 22일

< V0.9.6 >
  - 최초 공개
  + 2020년 1월 28일