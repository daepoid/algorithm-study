import java.util.ArrayList;
import java.util.List;

public class Q172927 {
    public static void main(String[] args) {
        Q172927 q172927 = new Q172927();
//        int[] picks = {1, 3, 2};
//        String[] minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};
        int[] picks = {1, 0, 1};
        String[] minerals = {"stone", "stone", "stone", "stone", "stone", "iron", "iron", "iron", "iron", "iron", "diamond", "diamond"};
        int result = q172927.solution(picks, minerals);
        System.out.println("result = " + result);
    }

    public int solution(int[] picks, String[] minerals) {
        int answer = 0, diamond = 0, iron = 0, stone = 0;
        List<Pack> packs = new ArrayList<>();
        int sumOfPicks = picks[0] + picks[1] + picks[2];
        for (int i = 0; i < minerals.length && i < sumOfPicks * 5; i++) {
            switch (minerals[i]) {
                case "diamond" -> diamond++;
                case "iron" -> iron++;
                case "stone" -> stone++;
            }
            if ((i + 1) % 5 == 0 || i == minerals.length - 1) {
                packs.add(new Pack(diamond, iron, stone));
                diamond = 0;
                iron = 0;
                stone = 0;
            }
        }
        packs.sort((a, b) -> b.getValue() - a.getValue());
        for (Pack pack : packs) {
            if (picks[0] > 0) {
                picks[0]--;
                answer += pack.getTired("diamond");
            } else if (picks[1] > 0) {
                picks[1]--;
                answer += pack.getTired("iron");
            } else if (picks[2] > 0) {
                picks[2]--;
                answer += pack.getTired("stone");
            }
        }
        return answer;
    }

    private class Pack {
        int diamond;
        int iron;
        int stone;

        Pack(int diamond, int iron, int stone) {
            this.diamond = diamond;
            this.iron = iron;
            this.stone = stone;
        }

        int getValue() {
            return this.diamond * 25 + this.iron * 5 + this.stone;
        }

        int getTired(String pick) {
            int val = 0;
            switch (pick) {
                case "diamond" -> val = diamond + iron + stone;
                case "iron" -> val = diamond * 5 + iron + stone;
                case "stone" -> val = diamond * 25 + iron * 5 + stone;
            }
            return val;
        }
    }
}
