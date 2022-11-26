IF exist "$(SolutionDir)MoonPatrol\bin\$(Platform)\$(Configuration)\resources" rd "$(SolutionDir)MoonPatrol\bin\$(Platform)\$(Configuration)\resources"
MKDIR  "$(SolutionDir)MoonPatrol\bin\$(Platform)\$(Configuration)\resources"
XCOPY "$(SolutionDir)MoonPatrol\resources" "$(SolutionDir)MoonPatrol\bin\$(Platform)\$(Configuration)\resources"/e /h /y