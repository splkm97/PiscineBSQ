# PiscineBSQ

## function list

```c
char    **read_map(int fd, int maplen, int *xsize, int *ysize);
  // 입력받은 fd가 가리키는 파일에서 maplen 라인의 인풋을 받아,
  // xsize, ysize를 계산하고 map 이차원 배열을 생성
void    parse_map(char **raw_map, t_point *pts, char *charset);
  // 입력받은 raw_map 에서 가장 큰 정사각형을 구하기 위해 맵을 파싱
  // 이후 왼쪽 위 지점과 오른쪽 아래 지점을 각각 pts[1] pts[2] 에 저장
void    fill_map(char **raw_map, t_point *pts, char *charset);
  // 입력받은 pts에서 지도 크기, 왼쪽 위, 오른쪽 아래 포인트를 받아
  // raw_map을 filled_map으로 변환
void    print_map(char **filled_map, int xsize, int ysize);
  // map 을 단순히 출력
```


## role discription

- ALEE:

```c
int get_map_width(int fd);  //  파일 핸들을 통하여 맵의 너비 크기를 반환
void fill_map();      //  가장 큰 직사각형 위치를 표시
void print_map(char **filled_map, int xsize, int ysize);     //  맵 출력
    // & norminette fix
```

- KALEE:

```c
int get_map_height();
char **read_map();
void parse_map(char **raw_map, t_point *pts, char *charset);
    // & main logic & header file & Makefile
```
