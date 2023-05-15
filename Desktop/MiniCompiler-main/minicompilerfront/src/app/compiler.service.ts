import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class CompilerService {
  apiServerUrl: string="http://localhost:8080";

  constructor(private http:HttpClient) { }
  public compile(code:string):Observable<string>{
    return this.http.post(`${this.apiServerUrl}/api/v1/compiler/compile`,code,{responseType:"text"});
}
}
