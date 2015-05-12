import scala.Console._

object Strings{
  def main(args: Array[String]){
    val k: Int = readInt()
    val string: String = readLine()
    var sub_strings: List[String] = List[String]()
    var used: List[Char] = List[Char]()
    var current = ""
    for (char <- string){
      if(used.contains(char)){
        println("Used")
        println(used)
        current = current.concat(char.toString())
      }
      else{
        if(current != ""){
          sub_strings = sub_strings ::: List(current)
        }
        current = ""
        current = current.concat(char.toString())
        used = used ::: List(char)
      }
    }
    for(string <- sub_strings){
      println(string)
    }
    if(sub_strings.length < k){
      println("No")
      return
    }
  }
}
