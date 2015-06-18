#include <iostream>
#include <stack>
using namespace std;
int X, Y;
int x1, y1;
int x2, y2;
int graph[1000][1000];
int marked[1000][1000];
int goal_found;
class Point{
    public:
        int x;
        int y;
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
};
void get_adjacent(int value, Point p, stack<Point>& adj_vertices){
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int x = p.x;
    int y = p.y;
    if(value == 0){
        for(int i=0; i<4; i++){
            if(x + dx[i] > 0 && x + dx[i] < X && y + dy[0] > 0 && y + dy[0] < Y){
                adj_vertices.push(Point(x+dx[i], y+dy[i]));
            }
        }
    }
    else if(value == 1){
    //He falls down
        if(x > 0 && x < X && y + 1 > 0 && y + dy[0] < Y){
            adj_vertices.push(Point(x, y+1));
        }
    }
}

int dfs(Point source){
    if(marked[source.x][source.y] == 1)
        return 0;
    if(source.x == x2 && source.y == y2){
        goal_found = 1;
        return 1;
    }
    stack<Point> adj_vertices;
    get_adjacent(graph[source.x][source.y], source, adj_vertices);
    marked[source.x][source.y] = 1;
    while(!adj_vertices.empty()){
        Point vertex = adj_vertices.top();
        adj_vertices.pop();
        dfs(vertex);
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char temp;
            cin>>temp;
            if(temp == '.'){
                graph[i][j] = 0;     
            }
            else if(temp == 'X'){
                graph[i][j] = 1;
            }
            marked[i][j] = 0;
        }
    }
    int goal = dfs(Point(x1, y1));
    if(goal){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
