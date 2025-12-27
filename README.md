### Dockerの仮想環境内でmakeするコマンド


docker run --rm -it \
  -e DISPLAY=host.docker.internal:0 \
  -v "$PWD":/work \
  cub3d \
  bash -lc "make && ./cub3D maps/test_min.cub"
