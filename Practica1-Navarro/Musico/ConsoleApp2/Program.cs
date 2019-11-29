using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {

            Orquesta or = new Orquesta("Orquesta1","Lomas",Orquesta.TipoOrquesta.Sinfonica);
            Console.WriteLine("Nombre: {0},Lugar: {1},Tipo: {2}", or.nombre, or.lugar, or.tipo);
            Console.ReadLine();//systemPause

            Instrumento inst = new Instrumento("Guitarra",Instrumento.TipoInstrumento.Guitarra);
            Console.WriteLine("Nombre: {0},Tipo:{1}", inst.nombre, inst.tipo);
            Console.ReadLine();//systemPause

            Musico musicoPrincipal = new Musico("Juan","Cabrera",34,inst);
            Console.WriteLine("Nombre: {0},Apellido:{1},Edad:{2},Instrumento:{3}",
            musicoPrincipal.nombre, musicoPrincipal.apellido, musicoPrincipal.edad, musicoPrincipal.instrumento);
            Console.ReadLine();//systemPause

            Musico m2 = new Musico("Pepe", "Grillo", 24, inst);

            or.musicos.Add(musicoPrincipal);
            or.musicos.Add(m2);

            Orquesta.printOrquesta(or);

           // Orquesta or2 =new Orquesta("Orquesta2","")
        }
    }
    
}
