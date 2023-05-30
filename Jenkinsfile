pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'main', credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git'
            }
        }
        stage('Cppcheck') {
            steps {
                bat 'cppcheck  . --platform=win64 --inconclusive --enable=all --rule-file=cppcheck_rules.xml --xml-version=2 --xml --output-file=cppcheck.xml'
            }
        }
        stage('Quality Gate') {
            steps {
                script{
                    // Read Cppcheck XML file into a string
                    def xmlString = readFile 'cppcheck.xml'

                    // Parse XML string using XmlSlurper
                    def xml = new XmlSlurper().parseText(xmlString)
                    
                    def errors = xml.errors.error
                    def warnings = xml.warnings

                    //def errorCount = errors.size()
                    def errorCount = errors.size()
                    def warningCount = warnings.size()
                    
                    echo "The number of errors is ${errorCount}"
                    echo "The number of warnings is ${warningCount}"

                    // Access elements in the XML document
                    //def errorCount = xml.@errors.toInteger()
                    //def warningCount = xml.@warnings.toInteger()
                    echo "Reading xml"
                    def errors = new XmlParser().parse(cppcheck.xml)

                    echo "Adding node to xml"
                    def errorNode = new NodeBuilder().error(id: 'TestingXMLEdit', severity:'Testseverity', msg:'Test msg', verbose:'Test Verbose', cwe:'561', inconclusive:'true', file0:"Sonarproject.c" {
                    location(file:"Sonarproject.c", line:"28", column:"5")
                    }
                    errors.append(errorNode)
                    
                    // Quality Gate criteria
                    def maxErrors = 3
                    def maxWarnings = 10

                    // Check if quality gate conditions are met
                    if (errorCount <= maxErrors && warningCount <= maxWarnings) {
                        echo "Quality Gate: Passed"
                    } else {
                        //error "Quality Gate: Failed - Exceeded maximum errors or warnings"
                    }
                }
            }
        }
        stage('Clang format') {
            steps {
                println "Checking suggestions for formatting..."
                bat "clang-format --style=llvm --dry-run *.c"
                println "Reformatting started..."
                bat 'clang-format -i *.c'
                println "Reformatting done."
            }
        }
    }
    post {
        always {
            publishCppcheck pattern:'cppcheck.xml'
        }
    }
}


// clang-format -i *.c
// clang-format --style=llvm --dry-run *.c
