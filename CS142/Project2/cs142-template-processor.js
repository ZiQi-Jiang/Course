function Cs142TemplateProcessor(template){
    
    this.template = template;

    

}

Cs142TemplateProcessor.prototype.fillIn = function(dictionary)
{
    var reg = /{{.*?}}/g; // ? non-greedy mode; g: global search

    var res = this.template.replace(reg,match=>{
        var property = match.slice(2,match.length-2);
        var word = dictionary[property];
        if( word === undefined) {return "";}
        else {return word;}
    });

    return res;

};


