using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace AspCoreStates.Pages.State
{
    public class ReadModel : PageModel
    {
        public string Name { get; set; }
        public int? Age { get; set; }



        public void OnGet()
        {/*
            // Retrieving user input from session
            Name = HttpContext.Session.GetString("Name");
            Age = HttpContext.Session.GetInt32("Age").Value;
           */
            // Retrieving user input from cookies
            Name = Request.Cookies["Name"];
            Age = int.Parse(Request.Cookies["Age"]);
            /*
            if (Request.Cookies.TryGetValue("Name", out string name))
            {
                Name = name;
            }

            if (Request.Cookies.TryGetValue("Age", out string age))
            {
                int.TryParse(age, out int parsedAge);
                Age = parsedAge;
            }
            */
        }

        public IActionResult OnPost()
        {
            // Redirect to the Write page if there's no data posted
            return RedirectToPage("/Write");
        }
    }
}
/*using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace AspCoreStates.Pages.State
{
    public class ReadModel : PageModel
    {
        public string MyName { get; set; }
        public int? MyAge { get; set; }
       
        public void OnGet()
        {
            //for cookies
            MyName = Request.Cookies["Name"];
            
             //for Session
            MyName = HttpContext.Session.GetString("Name");
            MyAge = HttpContext.Session.GetInt32("Age").Value;
            
        }
    }
}
*/