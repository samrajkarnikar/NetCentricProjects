using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace AspCoreStates.Pages.State
{
    public class WriteModel : PageModel
    {
        public IActionResult OnPost(string name, int age)
        {/*
            // Storing user input in session
            HttpContext.Session.SetString("Name", name);
            HttpContext.Session.SetInt32("Age", age);*/
            
            // Storing user input in cookies
            CookieOptions options = new CookieOptions();
            options.Expires = DateTime.Now.AddMinutes(1);
            Response.Cookies.Append("Name", name, options);
            Response.Cookies.Append("Age", age.ToString(), options);
            
            return RedirectToPage("/State/Read");
        }
        public void OnGet()
        {
        }
    }
}


/*using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace AspCoreStates.Pages.State
{
    public class WriteModel : PageModel
    {
        public void OnGet()//Page Load
        {/*
       //for session
            HttpContext.Session.SetString("Name", "Jos Butter");
            HttpContext.Session.SetInt32("Age", 33);
            
//for cookies
            CookieOptions options = new CookieOptions();
            options.Expires = DateTime.Now.AddMinutes(1);
            Response.Cookies.Append("Name", "Bruce Wayne",options);
        }
    }
}*/
