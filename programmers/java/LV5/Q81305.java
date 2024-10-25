public class Q81305 {

    public static void main(String[] args) {
        Q81305 question = new Q81305();
//        int k = 3;
//        int[] num = {12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1};
//        int[][] links = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {8, 5}, {2, 10}, {3, 0}, {6, 1}, {11, -1}, {7, 4}, {-1, -1}, {-1, -1}};

//        int k = 1;
//        int[] num = {6, 9, 7, 5};
//        int[][] links = {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}};

//        int k = 4;
//        int[] num = {6, 9, 7, 5};
//        int[][] links = {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}};

        int k = 2;
        int[] num = {6, 9, 7, 5};
        int[][] links = {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}};

        int result = question.solution(k, num, links);
        System.out.println(result);
    }

    public class Node{
        int num, val, sum;
        Node left, right, parent;
        Node(int num, int val, Node left, Node right) {
            this.num = num;
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    Node[] buildNodes(int[] num, int[][] links) {
        Node[] nodes = new Node[num.length];
        for (int i = 0; i < num.length; i++) {
            Node left = null, right = null;
            if(links[i][0] != -1 && links[i][0] < i) {
                left = nodes[links[i][0]];
            } else if(links[i][0] != -1 && links[i][0] > i) {
                nodes[links[i][0]] = new Node(links[i][0], num[links[i][0]], null, null);
                left = nodes[links[i][0]];
            }

            if(links[i][1] != -1 && links[i][1] < i) {
                right = nodes[links[i][1]];
            } else if(links[i][1] != -1 && links[i][1] > i) {
                nodes[links[i][1]] = new Node(links[i][1], num[links[i][1]], null, null);
                right = nodes[links[i][1]];
            }
            if(nodes[i] == null) {
                nodes[i] = new Node(i, num[i], left, right);
            } else {
                nodes[i].left = left;
                nodes[i].right = right;
            }

            if(left != null) left.parent = nodes[i];
            if(right != null) right.parent = nodes[i];
        }
        return nodes;
    }

    Node findRoot(Node[] nodes) {
        Node temp = nodes[0];
        while(temp.parent != null) {
            temp = temp.parent;
        }
        return temp;
    }

    int[] cutNodes(int threshold, Node curr, Node[] nodes) {
        if(curr.left == null && curr.right == null) {
            curr.sum = curr.val;
            return curr.val > threshold ? new int[]{-1, curr.sum} : new int[]{0, curr.sum};
        }

        Node left = null, right = null;
        int[] lResult = new int[2], rResult = new int[2];
        if(curr.left == null) {
            left = new Node(-1, 0, null, null);
            left.sum = 0;
        } else {
            left = curr.left;
            lResult = cutNodes(threshold, curr.left, nodes);
        }

        if(curr.right == null) {
            right = new Node(-1, 0, null, null);
            right.sum = 0;
        } else {
            right = curr.right;
            rResult = cutNodes(threshold, curr.right, nodes);
        }

        if(lResult[0] == -1 || rResult[0] == -1) {
            return new int[]{-1, -1};
        }

        int[] result = {lResult[0] + rResult[0], Math.max(lResult[1], rResult[1])};
        if(left.sum + right.sum + curr.val <= threshold) {
            curr.sum = left.sum + right.sum + curr.val;
        }

        else if(left.sum < right.sum) {
            if (left.sum + curr.val <= threshold) {
                result[0]++;
                curr.sum = left.sum + curr.val;
            } else {
                result[0] += 2;
                curr.sum = curr.val;
            }
        } else {
            if(right.sum + curr.val <= threshold) {
               result[0]++;
               curr.sum = right.sum + curr.val;
            } else {
                result[0] += 2;
                curr.sum = curr.val;
            }
        }
        result[1] = Math.max(result[1], curr.sum);
        return result;
    }

    public int solution(int k, int[] num, int[][] links) {
        int high = 0, low = -1;
        for (int n : num) {
            high += n;
            low = Math.max(low, n);
        }

        Node[] nodes = buildNodes(num, links);
        Node root = findRoot(nodes);

        int answer = high;
        int mid = (low + high) / 2;
        while(low < high) {
            mid = (low + high) / 2;
            Node[] copiedNodes = new Node[nodes.length];
            System.arraycopy(nodes, 0, copiedNodes, 0, nodes.length);
            Node copiedRoot = copiedNodes[root.num];
            int[] result = cutNodes(mid, copiedRoot, copiedNodes);
            if (result[0] == -1) {
                low = mid + 1;
                continue;
            }

            if (result[0] <= k - 1) {
                high = mid;
                answer = mid;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
}
