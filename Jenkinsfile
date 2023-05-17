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
                bat 'cppcheck  . --platform=win64 --inconclusive --enable=all --xml-version=2 --xml --output-file=cppcheck.xml'
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

                    // Quality Gate criteria
                    def maxErrors = 3
                    def maxWarnings = 10

                    // Check if quality gate conditions are met
                    if (errorCount <= maxErrors && warningCount <= maxWarnings) {
                        echo "Quality Gate: Passed"
                    } else {
                        error "Quality Gate: Failed - Exceeded maximum errors or warnings"
                    }
                    }
            }
        }
    }
    post {
        always {
            publishCppcheck pattern:'cppcheck.xml'
        }
    }
}
