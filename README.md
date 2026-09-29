# \## 🛠️ CUDA 개발 환경 설정

# 

# \### 1. CUDA Toolkit 설치

# 

# \*\*NVIDIA 웹사이트 방문\*\*

# \[NVIDIA CUDA Toolkit 다운로드](https://developer.nvidia.com/cuda-downloads)에 접속합니다.

# 

# \*\*운영 체제 선택\*\*

# 

# \* OS: Windows

# \* 시스템에 맞는 CUDA Toolkit 버전 선택

# \* Installer Type에 맞는 설치 파일 다운로드

# 

# \*\*설치 실행\*\*

# 다운로드한 설치 파일을 실행하고 기본 설정으로 설치합니다.

# 일반적으로 \*\*Express Installation\*\*을 권장합니다.

# 

# \---

# 

# \### 2. Visual Studio 2022 설치 및 설정

# 

# \*\*Visual Studio 2022 설치\*\*

# 아직 설치하지 않았다면 Microsoft 웹사이트에서 Visual Studio 2022 Community(무료) 또는 Professional/Enterprise 버전을 설치합니다.

# 

# \*\*워크로드 선택\*\*

# 

# 설치 과정에서 다음 워크로드를 선택합니다.

# 

# > \*\*Desktop development with C++ (C++를 사용한 데스크톱 개발)\*\*

# 

# 이미 Visual Studio가 설치되어 있다면 \*\*Visual Studio Installer → 수정(Modify)\*\*에서 해당 워크로드를 추가할 수 있습니다.

# 

# \---

# 

# \### 3. CUDA 프로젝트 생성

# 

# 1\. \*\*Visual Studio 2022\*\*를 실행합니다.

# 2\. \*\*새 프로젝트 만들기\*\*를 선택합니다.

# 3\. 검색창에 `CUDA`를 입력합니다.

# 4\. \*\*CUDA 12.x Runtime\*\* 템플릿을 선택합니다.

# 

# &#x20;  \* 설치한 CUDA Toolkit 버전에 따라 템플릿의 버전이 다를 수 있습니다.

# 5\. 프로젝트 이름과 저장 위치를 지정한 후 \*\*만들기(Create)\*\*를 클릭합니다.

# 

# \---

# 

# \### 4. 프로젝트 설정 확인

# 

# 솔루션 탐색기에서 프로젝트를 우클릭한 후 \*\*속성(Properties)\*\*을 선택합니다.

# 

# \*\*CUDA C/C++ 설정\*\*

# 

# `CUDA C/C++` 항목에서 GPU 아키텍처 설정을 확인합니다.

# 

# 일반적으로 다음과 같은 형식으로 설정되어 있습니다.

# 

# ```text

# compute\_XX, sm\_XX

# ```

# 

# 사용 중인 NVIDIA GPU에 맞는 Compute Capability가 설정되어 있는지 확인합니다.

# 

# \---

# 

# \### 5. 테스트 코드 작성 및 실행

# 

# CUDA 프로젝트를 생성하면 기본적으로 `kernel.cu` 파일이 생성되며 간단한 CUDA 코드가 포함되어 있습니다.

# 

# 프로젝트를 빌드한 후 \*\*F5\*\*를 눌러 실행하여 CUDA 개발 환경이 정상적으로 구성되었는지 확인합니다.

# 

# \---

# 

# \### ⚠️ 주의사항

# 

# \* \*\*NVIDIA GPU가 설치되어 있어야 합니다.\*\*

# \* CUDA Toolkit과 \*\*Visual Studio 버전 간의 호환성\*\*을 확인해야 합니다.

# \* NVIDIA GPU 드라이버를 최신 버전으로 업데이트하는 것을 권장합니다.

# \* GPU 아키텍처 설정은 사용 중인 GPU의 Compute Capability에 맞게 설정해야 합니다.

# 

# \---

# 

# \## 📖 Project Documentation

# 

# 프로젝트의 자세한 설명 및 구현 과정은 아래 Notion 문서에서 확인할 수 있습니다.

# 

# 👉 \[03. Rays: A Simple Camera and Background](https://ivy-face-1df.notion.site/03-Rays-a-Simple-Camera-and-Background-3eaf2a3a5fb58000a639fb49a6a5a451?pvs=143)



