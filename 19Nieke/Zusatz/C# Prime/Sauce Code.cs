using System;
using System.Collections.Generic;

namespace Prime
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Wie viele Primzahlen sollen gesucht werden: ");

            List<int> primes = new List<int>();
            primes.Add(2);
            int upperLimit = 0;
            int number = 3;
            try
            {
                upperLimit = (int.Parse(Console.ReadLine()));
                if (upperLimit < 1) throw new Exception();
            }
            catch (Exception)
            {
                Console.WriteLine("Falsche Eingabe");
                return;
            }

            while (primes.Count < upperLimit)
            {
                getPrimes(ref primes, number);
                number++;
            }
            /*
            foreach(int i in primes)
            {
                Console.Write(i + "  ");
            }
            */
        }

        private static void getPrimes(ref List<int> list, int number)
        {
            foreach(int i in list)
            {
                if (number % i == 0) return;
            }
            Console.Write(number + "  ");
            list.Add(number);
        }

    }
}
