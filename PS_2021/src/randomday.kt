import java.util.*

class randomday {

}

fun randomDay(): String{
    val week = arrayOf("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday")
    return  week[Random().nextInt(week.size)]
}

fun fishFood(day: String) : String{
    return when (day){
        "Monday" -> "flakes"
        "Wednesday" -> "redworms"
        "Thursday" -> "granules"
        "Friday" -> "mosquitoes"
        "Sunday" -> "plankton"
        else -> "nothing"
    }
}

fun feedTheFish(){
    val day = randomDay()
    val food = fishFood(day)
    println("Today is $day and the fish fish eat $food")
}

fun main(){
    feedTheFish()
}
