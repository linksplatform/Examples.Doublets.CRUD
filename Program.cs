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
				Console.WriteLine($"The number of links in the the data store is {links.Count()}.");
                Console.WriteLine("Data store contents:");
				var query = new Link<uint>(links.Constants.Any, links.Constants.Any, links.Constants.Any);
                links.Each((link) => {
                    Console.WriteLine($"{links.Format(link)}");
					return links.Constants.Continue;
                }, query);
                link = links.Update(link, default, default);
                links.Delete(link);
            }
        }
    }
}
