using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

namespace HelloWorld.Doublets.DotNet
{
    class Program
    {
        static void Main()
        {
            using (var links = new UnitedMemoryLinks<uint>("db.links"))
            {
                var link = links.Create();
                link = links.Update(link, link, link);
                Console.WriteLine("Hello World!");
                Console.WriteLine($"This is my first link: {links.Format(link)}");
                Console.WriteLine($"Total links in the storage: {links.Count()}.");
                link = links.Update(link, default, default);
                links.Delete(link);
            }
        }
    }
}
