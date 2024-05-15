#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // 기본 입출력을 위한 헤더파일
#include <stdlib.h> // 동적 메모리 할당, NULL, 랜덤 함수를 사용하기 위한 헤더파일
#include <string.h> // strlen, strcpy, strcmp를 사용하기 위한 헤더파일
#include <stdbool.h> // boolean 자료형을 사용하기 위한 헤더파일

typedef int DataType; // 코드 유지보수 증대를 위해 char를 DataType로 변경하여 해석


typedef struct Node { // 노드의 형태 정의
    struct Node* llink; // 왼쪽 요소를 가리키는 링크
    DataType data; // 동적 할당된 문자열을 가리키는 data
    struct Node* rlink; // 오른쪽 요소를 가리키는 링크
}Node; // 명칭은 Node

typedef struct {// 노드를 가리키는 헤드노드의 정의
    Node* head; // 맨 처음 노드를 가리키는 포인터
    int count; // 링크드 리스트의 길이를 저장하는 변수
}Headnode; // 명칭은 Headnode

// 링크드 리스트 생성부
Headnode* mk_L_list(){ // 빈 링크드 리스트 생성, 파라미터 : 없음
    Headnode* H = (Headnode*)malloc(sizeof(Headnode)); // 헤드노드를 동적 생성하여 H에 할당
    if(!H){ // 할당 못하면(H == NULL 의 역이므로 참)
        printf("동적 할당 실패!\n"); // 경고 메세지 출력
        exit(1); // 오류코드 반환 후 프로그램 종료
    }
    H->count = 0; // 카운트를 0으로 초기화
    H->head = NULL; // 갱글링 포인터 방지를 위해 NULL을 할당
    return H; // 동적 할당한 헤드노드의 주소 반환
}

// 삽입
Node* mknode(DataType data){ // 새로운 노드 생성, node_in함수에 종속적, 파라미터 : 복사받을 문자열의 주소
    Node* newnode = (Node*)malloc(sizeof(Node)); // 새로운 노드 생성
    if(!newnode){ // 할당 못하면(newnode == NULL 의 역이므로 참)
        printf("동적 할당 실패!(연결 리스트)\n"); // 경고 메세지 출력
        exit(1); // 오류코드 반환 후 프로그램 종료
    }

    newnode->data = data; // 동적할당된 cpydata를 newnode가 가리키게 함
    newnode->llink = NULL; // 갱글링 포인터 방지를 위해 NULL을 할당
    newnode->rlink = NULL; // 갱글링 포인터 방지를 위해 NULL을 할당

    return newnode; // 만들어진 노드의 주소 반환
}

void node_in_first(Headnode* H, Node* newnode, Node* prenode){ // 첫번째 노드로 만들기, node_in에 종속적, 파라미터 : 헤드노드 포인터, 새로운 노드의 주소, 이전 노드의 주소
    H->head = newnode; // 헤드 노드를 새로운 노드로 설정
    newnode->llink = newnode; // 자기 자신을 가리킴
    newnode->rlink = newnode; // 자기 자신을 가리킴
    H->count++; // 노드 수 증가
}
void node_in_normal(Headnode* H, Node* newnode, Node* prenode){ // 노드 끼워넣기, node_in에 종속적, 파라미터 : 헤드노드 포인터, 새로운 노드의 주소, 이전 노드의 주소
    newnode->llink = prenode; // 새 노드의 llink를 이전 노드로 설정
    newnode->rlink = prenode->rlink; // 새 노드의 rlink를 이전 노드의 rlink로 설정
    prenode->rlink->llink = newnode; // 이전 노드의 rlink가 가리키는 노드의 llink를 새 노드로 설정
    prenode->rlink = newnode; // 이전 노드의 rlink를 새 노드로 설정
    H->count++; // 노드 수 증가
}
Node* node_in(Headnode* H, DataType data, Node* prenode){ // 노드 생성 후 삽입, 종속 함수 2개 보유, 파라미터 : 헤드노드 포인터, 문자열 주소, 이전 노드의 주소
    Node* newnode = mknode(data); // 새로운 노드 할당

    if (!H->head) { // 리스트가 비어있을 경우
        node_in_first(H, newnode ,prenode); // 첫번째 노드로 만들기
    } else { // 리스트가 비어있지 않을 경우
        node_in_normal(H, newnode ,prenode); // 끼워넣기
    }
    return newnode; // 새로 생성한 노드의 주소 반환
}

// 삭제
void node_out_one(Headnode* H, Node* delnode){ // 빈 링크드 리스트로 만들기, node_out에 종속적, 파라미터 : 헤드노드 포인터, 지울 노드의 주소
    free(delnode); // 생성했던 노드의 동적 할당 해제

    H->head = NULL; // head포인터가 NULL을 가리키게 하여 빈 링크드 리스트임을 표시
    H->count--; // 노드의 수 카운트 1개 감소
}
void node_out_normal(Headnode* H, Node* delnode){ // 지정한 노드 제거하기, node_out, node_out_head에 종속적, 파라미터 : 헤드노드 포인터, 지울 노드의 주소
    delnode->llink->rlink = delnode->rlink; // 지우는 노드의 왼쪽 링크 즉, 이전 노드의 rlink가 지우는 노드의 다음 노드를 가리키게 한다.
    delnode->rlink->llink = delnode->llink; // 지우는 노드의 오른쪽 링크 즉, 다음 노드의 llink가 지우는 노드의 이전 노드를 가리키게 한다.

    free(delnode); // 생성했던 노드의 동적 할당 해제
    H->count--; // 노드의 수 카운트를 1개 감소시킨다.
}
void node_out_head(Headnode* H, Node* delnode){ // 헤드노드 옮기고 사이에 낀 노드 제거하기, node_out에 종속적, 파라미터 : 헤드노드 포인터, 지울 노드의 주소
    H->head = H->head->rlink; // 헤드포인터가 가리키는 노드의 오른쪽 노드를 헤드노드로 만든다.
    node_out_normal(H, delnode); // 지정한 노드 제거하기
}
void node_out(Headnode* H, Node* delnode){ // 지정한 노드 제거하기, 종속 함수 3개 보유, 파라미터 : 헤드노드 포인터, 지울 노드의 주소
    if(!H->head){ // 리스트가 비었으면
        return; // 함수 종료
    } else if(H->head == delnode && H->head == H->head->rlink){ //리스트에 원소가 하나이면
        node_out_one(H, delnode); // 빈 링크드 리스트로 만들기
        return; // 함수 종료
    } else if(H->head == delnode && !(H->head == H->head->rlink)){ // 지우는게 head 노드이면
        node_out_head(H, delnode); // 헤드 노드 옮기고 지정한 노드 제거하기
        return; // 함수 종료
    } else { // 그냥 제거해도 이상 없을때
        node_out_normal(H, delnode); // 지정한 노드 제거하기
        return; // 함수 종료
    }
}

// 탐색
Node* node_search_int_L(Node* point){ // 왼쪽으로 한 칸 이동, node_serch에 종속, 파라미터 : 시작 노드의 주소
    point = point->llink; // point의 왼쪽을 point로 새로 지정
    return point; // point 반환
}
Node* node_search_int_R(Node* point){ // 오른쪽으로 한 칸 이동, node_serch에 종속, 파라미터 : 시작 노드의 주소
    point = point->rlink; // point의 왼쪽을 point로 새로 지정
    return point; // point 반환
}
Node* node_search(Headnode* H, Node* point, bool RL){ // 노드 지정한 횟수만큼 탐색후 그 주소 반환, 종속 함수 2개 보유, 파라미터 : 헤드노드 포인터, 시작 노드의 주소, 회전옵션
    if(H->head == NULL){ // 노드가 비어있으면
        return NULL; // NULL 반환
    } else if(RL == false){ // 회전옵션이 false(오른쪽이면)
        return node_search_int_R(point); // 오른쪽으로 한칸 이동한 노드의 주소를 반환
    } else { // 회전옵션이 true(왼쪽이면)
        return node_search_int_L(point); // 왼쪽으로 한 칸 이동한 노드의 주소를 반환
    }
}

// 메인 구현부
int main() {
    int N; // 건너뛸 횟수
    int K; // 사람의 수
    scanf("%d %d", &K, &N); // 건너뛸 횟수와 사람의 수 입력받기

    Headnode* H = mk_L_list(); // 새로운 링크드 리스트 생성
    Node* cursor = H->head; // 삽입 및 삭제용 커서 생성

    // 삽입부
    for(int i = 1; i <= K; i++) {
            cursor = node_in(H, i, cursor); // 입력값을 노드에 삽입하고, 노드 주소 커서에 넘겨주기
    }

    bool RL = false; // 방향 확인 및 랜덤 지정용 RL 선언

    cursor = H->head->llink; //커서 일단 head노드가 가리키는 노드의 llink로 초기화
    printf("<");
    // 삭제부
    while (H->head != NULL) { // 리스트가 비어있지 않을때까지
        // N만큼 이동
        for (int i = 0; i < N; i++) {
            cursor = node_search(H, cursor, RL); // 방향옵션쪽으로 1칸 이동
        }
        printf("%d", cursor->data); // 지울 노드 출력
        if(!(cursor == H->head->llink) || !(cursor->rlink == cursor)){
            printf(", ");
        }
        Node* pre_cursor = node_search(H, cursor, !RL); // 이전 노드를 가리키는 포인터를 저장

        node_out(H, cursor); // 현재 노드를 삭제
        cursor = pre_cursor; // 이전 노드로 이동
    }
    // 모든 노드 삭제 후 동적할당한 헤드노드 해제
    free(H);
    printf(">");

    return 0;
}