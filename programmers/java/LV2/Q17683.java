import java.util.Arrays;

public class Q17683 {
    public static void main(String[] args) {
        Q17683 question = new Q17683();
//        String m = "ABCDEFG";
//        String[] musicinfos = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};

        String m = "CC#BCC#BCC#BCC#B";
        String[] musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};

        String result = question.solution(m, musicinfos);
        System.out.println("result = " + result);
    }

    public String replaceSharp(String melody) {
        return melody
                .replace("C#", "c")
                .replace("D#", "d")
                .replace("E#", "e")
                .replace("F#", "f")
                .replace("G#", "g")
                .replace("A#", "a")
                .replace("B#", "b");
    }

    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        int maxLen = 0;
        Arrays.sort(musicinfos);
        for (String musicInfo : musicinfos) {
            String[] tokens = musicInfo.split(",");
            String[] beginTime = tokens[0].split(":");
            String[] endTime = tokens[1].split(":");
            int musicLength = (Integer.parseInt(endTime[0]) - Integer.parseInt(beginTime[0])) * 60 + (Integer.parseInt(endTime[1]) - Integer.parseInt(beginTime[1]));

            String name = tokens[2];
            String melody = replaceSharp(tokens[3]);
            m = replaceSharp(m);

            while (musicLength > melody.length()) {
                melody += melody;
            }

            melody = melody.substring(0, musicLength);
            if (melody.contains(m) && maxLen < musicLength) {
                maxLen = musicLength;
                answer = name;
            }
        }
        return answer;
    }
}
