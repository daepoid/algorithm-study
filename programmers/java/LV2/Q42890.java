import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Q42890 {

    int totalColumnSize;
    List<Set<Integer>> candidateKeys;
    String[][] copiedRelation;

    public static void main(String[] args) {
        Q42890 question = new Q42890();
        String[][] relation = {
                {"100", "ryan", "music", "2"},
                {"200", "apeach", "math", "2"},
                {"300", "tube", "computer", "3"},
                {"400", "con", "computer", "4"},
                {"500", "muzi", "music", "3"},
                {"600", "apeach", "music", "2"}};
        int result = question.solution(relation);
        System.out.println("result = " + result);
    }

    void combination(int idx, int columnCount, Set<Integer> set) {
        if (columnCount == 0) {
            if (isUnique(set) && isMinimal(set)) {
                candidateKeys.add(set);
            }
            return;
        }

        for (int i = idx; i < totalColumnSize; i++) {
            Set<Integer> temp = new HashSet<>(set);
            temp.add(i);
            combination(idx + 1, columnCount - 1, temp);
        }
    }

    boolean isUnique(Set<Integer> keys) {
        Set<String> set = new HashSet<>();
        for (String[] row : copiedRelation) {
            StringBuilder sb = new StringBuilder();
            for (int col : keys) {
                sb.append(row[col]);
                sb.append("_");
            }
            if (set.contains(sb.toString())) return false;
            else set.add(sb.toString());
        }
        return true;
    }

    boolean isMinimal(Set<Integer> keys) {
        for (Set<Integer> candidateKey : candidateKeys) {
            if (keys.containsAll(candidateKey)) return false;
        }
        return true;
    }

    public int solution(String[][] relation) {
        totalColumnSize = relation[0].length;
        copiedRelation = relation;
        candidateKeys = new ArrayList<>();

        for (int i = 1; i <= totalColumnSize; i++) {
            combination(0, i, new HashSet<>());
        }

        return candidateKeys.size();
    }
}
