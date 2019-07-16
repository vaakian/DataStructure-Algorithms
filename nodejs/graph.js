/*
  无权无向图DFS BFS
  BFS使用队列（类似树的层序遍历）
  DFS使用栈or递归调用（类似树的前后序遍历）
*/

class Graph {
  constructor(graph) {
    this.graph = graph;
    this.parent = {}
  }
  show() {
    console.log(this.graph)
  }
  // 递归实现
   DFS_R(vertex) {
    const visited = []
    // 递归调用可使用栈实现同样功能
    // 此处进行科里化
    const GetEdges = (vertex) => this.graph[vertex]
    const InnerTravel = (vertex) => {
      // 访问
      console.log(vertex);
      // 标记已经访问
      visited.push(vertex);
      for(let node of GetEdges(vertex)) {
        if(visited.indexOf(node) == -1)
          InnerTravel(node);
      }
    }
    InnerTravel(vertex);
  }
  DFS(s) {
    const stack = []
    const seen = []
    stack.push(s);
    seen.push(s);
    while (stack.length) {
      const cur = stack.pop();
      console.log(cur);
      const nodes = this.graph[cur];
      for(let node of nodes) {
        // 入栈则表示已经访问过（因为同层级）
        if (seen.indexOf(node) == -1) {
          stack.push(node);
          seen.push(node);
        }
      }
      // 如果没访问过，就输出
      if (seen.indexOf(cur) == -1) {
        console.log(cur)
        // 标记访问
        seen.push(cur)
      }
    }
  }
  BFS(s) {
    const queue = [];
    const seen = [];
    // 只要加到队列里，就认为访问过
    queue.push(s);
    seen.push(s);
    this.parent[s] = null;
    while (queue.length) {
      // console.log({queue});
      // 出队列
      const cur = queue.shift();
      // 访问
      console.log(cur);
      // 获取邻居节点
      const nodes = this.graph[cur];
      // 将未访问的邻节点入队列
      for (let node of nodes) {
        // 不重复入队列，且未访问过
        
        if (seen.indexOf(node) == -1) {
          this.parent[node] =  cur;
          queue.push(node);
          seen.push(node);
        }
      }
    }
    console.log(this.parent)
  }
}
// <V, E> 顶点和边
const graphVE = {
  "A": ["B", "C"],
  "B": ["A", "C", "D"],
  "C": ["A", "B", "D", "E"],
  "D": ["B", "C", "E", "F"],
  "E": ["C", "D"],
  "F": ["D"]
}
const graph = new Graph(graphVE)
graph.DFS_R('A')
// graph.DFS('C')

/*
Summary:
  递归本质上也是栈，所以用递归能实现的功能理论上可以用栈使其非递归化。
  分而治之，解决子问题。
  A --依赖--> B --依赖--> C
  C解决->B解决->A解决

  深度优先（DFS）：栈 | 递归
  广度优先（BFS）：队列
*/
