'use strict';
function cs142MakeMultiFilter(originalArray)
{
    var currentArray = originalArray.slice();
    // Must define arrayFilterre first, otherwise the arrayFilterer in the function is not defined
    var arrayFilterer = function(filterCriteria, callback)
    {
        if(typeof filterCriteria !== "function") {return currentArray;}
        else  
        {currentArray = currentArray.filter(filterCriteria);
        }
        if(typeof callback === "function") 
        {callback.call(originalArray,currentArray);}
        return arrayFilterer;

    } ;
    return arrayFilterer;
}
