using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.ResizableDirectMemory;

namespace HelloWorld.Doublets.DotNet
{
    class Program
    {
        static void Main()
        {
            using (var links = new ResizableDirectMemoryLinks<uint>("db.links"))
            {
                var link = links.Create();
                link = links.Update(link, link, link);
                Console.WriteLine("Hello World!");
                Console.WriteLine($"This is my first link: ({link}:{links.GetSource(link)}->{links.GetTarget(link)}).");
                Console.WriteLine($"Total links in the storage: {links.Count()}.");
                link = links.Update(link, default, default);
                links.Delete(link);
            }
        }
    }
}
