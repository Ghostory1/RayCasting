### CUDA 개발 환경 설정

#### 1. CUDA Toolkit 설치

**NVIDIA CUDA Toolkit 다운로드**

[CUDA Toolkit 다운로드](https://developer.nvidia.com/cuda-downloads)

NVIDIA 공식 CUDA 다운로드 페이지에서 운영체제와 시스템 환경에 맞는 CUDA Toolkit을 선택하여 다운로드합니다.

* OS: Windows
* Architecture: x86_64
* CUDA Toolkit 버전: 사용 환경에 맞는 버전 선택
* Installer Type: 환경에 맞는 설치 방식 선택

다운로드한 설치 파일을 실행하고 기본 설정으로 설치합니다.
일반적으로 **Express Installation**을 권장합니다.

#### 2. Visual Studio 2022 설치 및 설정

Visual Studio 2022가 설치되어 있지 않다면 Microsoft 공식 사이트에서 설치합니다.

설치 과정에서 다음 워크로드를 선택합니다.

> **Desktop development with C++ (C++를 사용한 데스크톱 개발)**

이미 Visual Studio가 설치되어 있다면 **Visual Studio Installer → 수정(Modify)**에서 해당 워크로드를 추가할 수 있습니다.

#### 3. CUDA 프로젝트 생성

1. Visual Studio 2022를 실행합니다.
2. **새 프로젝트 만들기**를 선택합니다.
3. 검색창에 `CUDA`를 입력합니다.
4. **CUDA 12.x Runtime** 템플릿을 선택합니다.

   * 설치한 CUDA Toolkit 버전에 따라 템플릿 버전이 다를 수 있습니다.
5. 프로젝트 이름과 저장 위치를 지정하고 **만들기(Create)**를 클릭합니다.

#### 4. 프로젝트 설정 확인

솔루션 탐색기에서 프로젝트를 우클릭한 후 **속성(Properties)**을 선택합니다.

**CUDA C/C++** 항목에서 GPU 아키텍처 설정을 확인합니다.

일반적으로 다음과 같은 형식으로 설정되어 있습니다.

```text
compute_XX, sm_XX
```

사용 중인 NVIDIA GPU에 맞는 Compute Capability가 설정되어 있는지 확인합니다.

#### 5. 테스트 코드 작성 및 실행

CUDA 프로젝트를 생성하면 기본적으로 `kernel.cu` 파일이 생성되며 간단한 CUDA 코드가 포함되어 있습니다.

프로젝트를 빌드한 후 **F5**를 눌러 실행하여 CUDA 개발 환경이 정상적으로 구성되었는지 확인합니다.

#### 주의사항

* NVIDIA GPU가 설치되어 있어야 합니다.
* CUDA Toolkit과 Visual Studio 버전의 호환성을 확인해야 합니다.
* NVIDIA GPU 드라이버가 최신 상태인지 확인하는 것을 권장합니다.
* GPU 아키텍처 설정은 사용 중인 GPU의 Compute Capability에 맞게 설정해야 합니다.

### Project Documentation

프로젝트의 자세한 설명 및 구현 과정은 아래 Notion 문서에서 확인할 수 있습니다.
- [01. 이미지 출력](https://ivy-face-1df.notion.site/01-3e9f2a3a5fb580f9bc3ff6eae6546f1b?pvs=143)
- [02. The Vec3 Class](https://ivy-face-1df.notion.site/02-The-Vec3-Class-3e9f2a3a5fb5800e9d4ef0578f092632?pvs=143)
- [03. Rays: A Simple Camera and Background](https://ivy-face-1df.notion.site/03-Rays-a-Simple-Camera-and-Background-3eaf2a3a5fb58000a639fb49a6a5a451?pvs=143)
- [04. Adding a Sphere](https://ivy-face-1df.notion.site/04-Adding-a-Sphere-3eaf2a3a5fb5805e931dd6886ecf57c3?pvs=143)
- [05. 표면 법선과 다중 객체](https://ivy-face-1df.notion.site/05-3f1f2a3a5fb5805eaa6add78fc14be1f?pvs=143)
- [06. 카메라 클래스](https://ivy-face-1df.notion.site/06-3f1f2a3a5fb58043814fccc389cc3ece?pvs=143)
- [07. 안티앨리어싱](https://ivy-face-1df.notion.site/07-3f1f2a3a5fb580b58e34c87457143b5d?pvs=143)
- [08. 확산 재질](https://ivy-face-1df.notion.site/08-3f2f2a3a5fb5808d8ed9cb39e5bf5bfc?pvs=143)
- [09. 메탈](https://ivy-face-1df.notion.site/09-Metal-3f3f2a3a5fb580fe80cbc5f6e65137ad?pvs=143)
- [10. 유전체](https://ivy-face-1df.notion.site/10-Dielectrics-3f3f2a3a5fb58008b721f6a0983d389c?pvs=143)