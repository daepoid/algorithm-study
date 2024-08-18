import java.util.*;

public class Q176962 {
    public static void main(String[] args) {
        Q176962 question = new Q176962();
//        String[][] plans = {{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}};
        String[][] plans = {{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};
        String[] result = question.solution(plans);
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < result.length; i++) {
            sb.append("\"" + result[i] + "\"");
            if (i != result.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        System.out.println(sb.toString());
        System.out.println(sb.toString().equals("[\"science\", \"history\", \"computer\", \"music\"]"));
    }

    public String[] solution(String[][] plans) {
        List<String> answer = new ArrayList<>();
        Stack<Task> stack = new Stack<>();
        Task[] tasks = Arrays.stream(plans)
                .map(Task::new)
                .sorted(Comparator.comparingInt(a -> a.time))
                .toArray(Task[]::new);

        for (int i = 0; i < tasks.length; i++) {
            Task now = tasks[i];
            if (i == tasks.length - 1) {
                answer.add(now.name);
                while (!stack.isEmpty()) answer.add(stack.pop().name);
            } else {
                Task next = tasks[i + 1];
                int spendTime = next.time - now.time;
                if (now.spend <= spendTime) {
                    answer.add(now.name);
                    spendTime -= now.spend;
                    while (!stack.isEmpty() && spendTime > 0) {
                        Task temp = stack.pop();
                        if (temp.spend <= spendTime) {
                            spendTime -= temp.spend;
                            answer.add(temp.name);
                        } else {
                            temp.spend -= spendTime;
                            stack.push(temp);
                            break;
                        }
                    }
                } else {
                    now.spend -= spendTime;
                    stack.push(now);
                }
            }
        }

        for (int i = 0; i < tasks.length; i++) {
            Task now = tasks[i];
            if (i != tasks.length - 1) {
                Task next = tasks[i + 1];
                int remainTime = next.time - now.time;
                if (now.spend < remainTime) {
                    remainTime -= now.spend;
                }

            }
        }
        return answer.toArray(new String[0]);
    }

    class Task {
        String name;
        int time;
        int spend;

        public Task(String[] plan) {
            this.name = plan[0];
            this.time = this.str2Time(plan[1]);
            this.spend = Integer.parseInt(plan[2]);
        }

        public int str2Time(String str) {
            int hour = Integer.parseInt(str.substring(0, 2));
            int minute = Integer.parseInt(str.substring(3, 5));
            return hour * 60 + minute;
        }
    }
}
