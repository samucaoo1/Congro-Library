#include <assert.h>
#include "Congro/Modules/Container/Graph/Graph.h"

int main(void) {
  TGRAPH_TYPE(int, int) graph = {0};
  size_t from = 0;
  size_t to = 0;
  OPSTATUS status = GRAPH_OPERATION(int, int, Init)(&graph);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = GRAPH_OPERATION(int, int, AddVertex)(&graph, 10, &from);
  if (status == STATUS_CONST(SUCCESS))
    status = GRAPH_OPERATION(int, int, AddVertex)(&graph, 20, &to);
  if (status == STATUS_CONST(SUCCESS))
    status = GRAPH_OPERATION(int, int, AddEdge)(&graph, from, to, 7);
  if (status == STATUS_CONST(SUCCESS)) {
    assert(GRAPH_OPERATION(int, int, HasEdge)(&graph, from, to));
    assert(!GRAPH_OPERATION(int, int, HasEdge)(&graph, to, from));
  }
  GRAPH_OPERATION(int, int, Destroy)(&graph);
  return status == STATUS_CONST(SUCCESS) ? 0 : 2;
}
