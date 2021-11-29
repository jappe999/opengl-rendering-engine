ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN apt-get update -y \
  && sudo apt-get install --no-install-recommends --no-install-suggests -y \
  libxmu-dev libxi-dev libgl-dev pkg-config libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev libxxf86vm-dev

# Install vcpkg and necessary dependencies
RUN git clone https://github.com/microsoft/vcpkg /app/vcpkg && /app/vcpkg/bootstrap-vcpkg.sh

CMD ["sleep", "infinity"]