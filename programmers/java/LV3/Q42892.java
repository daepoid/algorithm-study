import java.util.Arrays;
import java.util.stream.IntStream;

public class Q42892 {

    public static void main(String[] args) {
        Q42892 question = new Q42892();
        int[][] nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
        int[][] result = question.solution(nodeinfo);
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                System.out.printf("%d ", result[i][j]);
            }
            System.out.println();
        }
    }

    class Node {
        int y, x, idx;
        Node left, right;
        Node(int y, int x, int idx) {
            this.y = y;
            this.x = x;
            this.idx = idx;
        }
    }

    void update(Node parent, Node newChild) {
        if (newChild.x < parent.x) {
            if (parent.left == null) parent.left = newChild;
            else update(parent.left, newChild);
        } else {
            if (parent.right == null) parent.right = newChild;
            else update(parent.right, newChild);
        }
    }

    String preorder(Node node) {
        String route = "" + node.idx;
        if (node.left != null) route += (route.isBlank() ? "" : " ") + preorder(node.left);
        if (node.right != null) route += (route.isBlank() ? "" : " ") + preorder(node.right);
        return route;
    }

    String postorder(Node node) {
        String route = "";
        if (node.left != null) route += (route.isBlank() ? "" : " ") + postorder(node.left);
        if (node.right != null) route += (route.isBlank() ? "" : " ") + postorder(node.right);
        return route + (route.isBlank() ? "" : " ") + node.idx;
    }

    public int[][] solution(int[][] nodeinfo) {

        Node[] nodes = IntStream.range(0, nodeinfo.length)
                .mapToObj(i -> new Node(nodeinfo[i][1], nodeinfo[i][0], i + 1))
                .sorted((a, b) -> a.y != b.y ? b.y - a.y : a.x - b.x)
                .toArray(Node[]::new);

        Node root = nodes[0];
        for (int i = 1; i < nodes.length; i++) {
            update(root, nodes[i]);
        }

        return new int[][] {
                Arrays.stream(preorder(root).split(" ")).filter(s -> !s.isBlank()).mapToInt(Integer::parseInt).toArray(),
                Arrays.stream(postorder(root).split(" ")).filter(s -> !s.isBlank()).mapToInt(Integer::parseInt).toArray(),
        };
    }
}
