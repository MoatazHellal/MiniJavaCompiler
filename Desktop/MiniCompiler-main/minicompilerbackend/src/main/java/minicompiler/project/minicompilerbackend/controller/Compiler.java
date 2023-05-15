package minicompiler.project.minicompilerbackend.controller;

import org.springframework.web.bind.annotation.*;

import java.io.*;

@RestController()
@RequestMapping("api/v1/compiler")
public class Compiler {
    @PostMapping("/compile")
    public String executeCommand(@RequestBody(required = false) String content) {
        if (content != null) {
            String command = "C:\\Users\\USER\\Desktop\\MiniCompiler-main\\helper\\miniCompiler.exe < C:\\Users\\USER\\Desktop\\MiniCompiler-main\\helper\\mon_programme.txt";

            String fileName = "C:\\Users\\USER\\Desktop\\MiniCompiler-main\\helper\\mon_programme.txt"; // Replace with
                                                                                                        // your desired
                                                                                                        // file name

            try {
                File file = new File(fileName);
                FileWriter writer = new FileWriter(file);
                writer.write(content);
                writer.flush();
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();

            }
            try {
                Process process = Runtime.getRuntime()
                        .exec(String.format("cmd.exe /c " + command));

                BufferedReader inputReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));

                StringBuilder output = new StringBuilder();
                String line;
                while ((line = inputReader.readLine()) != null) {
                    output.append(line + "\n");
                }
                while ((line = errorReader.readLine()) != null) {
                    output.append(line + "\n");
                }

                return output.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "Error executing command: " + e.getMessage();

            }
        } else {
            return "";
        }
    }
}
